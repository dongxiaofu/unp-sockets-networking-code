//
// Created by chugang on 2020/6/28.
//
#include "common.h"

void err_sys(const char *str) {
    fprintf(stderr, "%s\n", str);
    exit(1);
}

void perror_sys(const char *str) {
    perror(str);
    exit(2);
}