cmake_minimum_required(VERSION 3.18)
project(codecrafters_http_server_c C)

set(CMAKE_C_STANDARD 11)

add_executable(codecrafters_http_server_c
        app/server.c
        app/headers/hashmap.h
        app/hashmap.c
        app/headers/httpparser.h
        app/httpparser.c
        app/headers/stringutils.h
        app/stringutils.c)
