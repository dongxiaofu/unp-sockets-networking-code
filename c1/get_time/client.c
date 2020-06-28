//
// Created by chugang on 2020/6/28.
//
#include "client.h"

void err_sys(const char *str);

int main(int argc, char **argv) {
    if (argc < 2) {
        err_sys("usage: a.out <IPAdress>");
    }
    client(argv);
    return 0;
}

void client(char **argv) {
    int sockfd, n;
    char recvline[MAX_LENGTH + 1];
    struct sockaddr_in servaddr;
    // 1.创建socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        err_sys("socket err");
    }
    // 将servaddr清空置零
    bzero(&servaddr, sizeof(servaddr));

    // 协议种类、端口、ip
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);          // 时间服务器的众所周知端口

    // 将“点分十进制” －> “二进制整数”，相反函数:inet_ntop
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) < 0) {
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        exit(1);
    }
    // 2.连接到socket
    if (connect(sockfd, (const struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        err_sys("connect error");
    }
    // 3.从socket读取数据
    while ((n = read(sockfd, recvline, MAX_LENGTH)) > 0) {
        if (fputs(recvline, stdout) == EOF) {
            err_sys("fputs error");
        }
    }
    if (n < 0) {
        err_sys("read error");
    }

    exit(0);
}

void err_sys(const char *str) {
    fprintf(stderr, "%s\n", str);
    exit(1);
}
