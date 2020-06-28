//
// Created by chugang on 2020/6/28.
//

#ifndef UNP_SOCKETS_NETWORKING_CODE_COMMON_H
#define UNP_SOCKETS_NETWORKING_CODE_COMMON_H

#include <stdio.h>
#include <stdlib.h>

//const int SERVER_PORT = 8002;
//const int MAX_LINE = 1024;
//上面定义常量的方法，导致错误：
//duplicate symbol '_SERVER_PORT' in:
//CMakeFiles/c5_echo_server.dir/c5/echo/server.c.o
//        CMakeFiles/c5_echo_server.dir/common.c.o
//        duplicate symbol '_MAX_LINE' in:
//CMakeFiles/c5_echo_server.dir/c5/echo/server.c.o
//        CMakeFiles/c5_echo_server.dir/common.c.o

#define SERVER_PORT  8002
#define MAX_LINE  1024

void err_sys(const char *str);

void perror_sys(const char *str);

#endif //UNP_SOCKETS_NETWORKING_CODE_COMMON_H
