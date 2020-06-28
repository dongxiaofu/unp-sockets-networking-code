//
// Created by chugang on 2020/6/28.
//

#ifndef UNP_SOCKETS_NETWORKING_CODE_CLIENT_H
#define UNP_SOCKETS_NETWORKING_CODE_CLIENT_H

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <zconf.h>
#include "../../common.h"

void client(char **argv);

void str_cli(FILE *fp, int sockfd);

#endif //UNP_SOCKETS_NETWORKING_CODE_CLIENT_H
