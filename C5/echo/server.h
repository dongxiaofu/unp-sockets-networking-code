//
// Created by chugang on 2020/6/28.
//

#ifndef UNP_SOCKETS_NETWORKING_CODE_SERVER_H
#define UNP_SOCKETS_NETWORKING_CODE_SERVER_H

#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include "../../common.h"

void echo_server();

void str_echo(int sockfd);

#endif //UNP_SOCKETS_NETWORKING_CODE_SERVER_H
