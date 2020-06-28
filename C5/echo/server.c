//
// Created by chugang on 2020/6/28.
//
#include "server.h"

int main() {
    echo_server();
    return 0;
}

void echo_server() {
    int listenfd;
    struct sockaddr_in sockaddr;

    // 1.建立socket
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    // 2.绑定
    bzero(&sockaddr, sizeof(sockaddr));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = SERVER_PORT;
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listenfd, (const struct sockaddr *) &sockaddr, sizeof(sockaddr)) < 0) {
        perror_sys("bind error:");
        exit(1);
    }

    // 3.监听
    if (listen(listenfd, 5) < 0) {
        perror_sys("listen error:");
        exit(2);
    }

    // 4.accept
    // todo 不理解。关闭了connfd，为何客户端还可以继续运行呢？
    for (;;) {
        int connfd = accept(listenfd, NULL, NULL);
        if (connfd < 0) {
            perror_sys("accept error:");
            exit(3);
        }
        int child_pid = fork();
        if (child_pid < 0) {
            perror_sys("create child process error:");
            exit(4);
        } else if (child_pid == 0) {
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        close(connfd);      // 在父进程提前关闭了connfd，子进程如何使用它？todo 为何没有发现此问题？
    }
}

void str_echo(int sockfd) {
    int n;
    char buf[MAX_LINE];
    again:
    while ((n = read(sockfd, buf, MAX_LINE)) > 0) {
        write(sockfd, buf, n);
    }
    if (n < 0) {
        goto again;
    }
}
