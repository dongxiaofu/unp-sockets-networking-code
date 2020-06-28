//
// Created by chugang on 2020/6/28.
//
#include "server.h"

int main() {
    server();
    return 0;
}

void server() {
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buf[MAX_LEN];
    time_t ticks;

    struct sockaddr_in client_name;
    int client_name_len = sizeof(client_name);
    // 1.创建socket
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // 2.将socket绑定到特定地址
    int result = bind(listenfd, (const struct sockaddr *) &servaddr, sizeof(servaddr));
    if (result < 0) {
        fprintf(stderr, "bind error");
        exit(1);
    }
    // 3.监听特定socket
    if (listen(listenfd, 5) < 0) {
        perror("listen error:");
        exit(1);
    }

    for (;;) {
        fprintf(stdout, "start\n");
//        if ((connfd = accept(listenfd, (struct sockaddr *) &client_name, (socklen_t *) &client_name_len)) < 0) {
        // 4.从监听的socket接收新socket
        if ((connfd = accept(listenfd, NULL, NULL)) < 0) {
            fprintf(stderr, "accept error");
            perror("perror打印错误信息");     // perror打印错误信息
            exit(1);
        }
        // 获取服务器时间
        ticks = time(NULL);
        // todo %.24s 与 %s 有何区别？
        snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&ticks));   // Sun Jun 28 18:56:16 2020
//        snprintf(buf, sizeof(buf), "%s\r\n", ctime(&ticks));     // Sun Jun 28 18:56:16 2020

        // 5.向新socket写入数据
        int n = write(connfd, buf, sizeof(buf));
        if (n < 0) {
            fprintf(stderr, "write error");
            exit(1);
        }
        close(connfd);
    }
}
