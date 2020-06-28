//
// Created by chugang on 2020/6/28.
//

#ifndef UNP_SOCKETS_NETWORKING_CODE_CLIENT_H
#define UNP_SOCKETS_NETWORKING_CODE_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <zconf.h>

const int MAX_LENGTH = 1024;

void client(char **argv);

#endif //UNP_SOCKETS_NETWORKING_CODE_CLIENT_H
