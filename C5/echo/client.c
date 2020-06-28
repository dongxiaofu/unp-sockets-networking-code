//
// Created by chugang on 2020/6/28.
//
#include "client.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        err_sys("usage:a.out <IP Address>");
    }
    client(argv);
    return 0;
}

void client(char **argv) {
    int connfd;
    struct sockaddr_in sockaddr;

    // 1.建立socket
    connfd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr.sin_port = SERVER_PORT;
    sockaddr.sin_family = AF_INET;

    // 错误 第一个参数
//    if (inet_pton(connfd, argv[1], &sockaddr.sin_addr.s_addr) < 0) {
//        perror_sys("ip error:");
//    }

    if (inet_pton(AF_INET, argv[1], &sockaddr.sin_addr.s_addr) < 0) {
        perror_sys("ip error:");
    }

    // 2.连接
    if (connect(connfd, (const struct sockaddr *) &sockaddr, sizeof(sockaddr)) < 0) {
        perror_sys("connect error:");
    }

    str_cli(stdin, connfd);
}

void str_cli(FILE *fp, int sockfd) {
    char buf[MAX_LINE];
    char msg[200] = "enter\n";
    fprintf(stdout, "%s", msg);
    while (fgets(buf, MAX_LINE, fp) > 0) {
        if (write(sockfd, buf, MAX_LINE) < 0) {
            perror_sys("write error:");
        }
        if (read(sockfd, buf, MAX_LINE) < 0) {
            perror_sys("read error:");
        }
        fputs(buf, stdout);
    }
}


