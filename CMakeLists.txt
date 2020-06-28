cmake_minimum_required(VERSION 3.16)
project(unp_sockets_networking_code)

set(CMAKE_CXX_STANDARD 14)

#chapter1
add_executable(c1_get_time_client
        c1/get_time/client.h
        c1/get_time/client.c common.c common.h)

add_executable(c1_get_time_server
        c1/get_time/server.h
        c1/get_time/server.c common.c common.h)

#chapter5
add_executable(c5_echo_client c5/echo/client.h c5/echo/client.c common.h common.c)
add_executable(c5_echo_server c5/echo/server.h c5/echo/server.c common.h common.c)
