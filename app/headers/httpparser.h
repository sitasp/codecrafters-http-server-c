//
// Created by ASUS on 22-04-2024.
//

#ifndef CODECRAFTERS_HTTP_SERVER_C_HTTPPARSER_H
#define CODECRAFTERS_HTTP_SERVER_C_HTTPPARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
#include "ctype.h"



typedef enum {
    GET,
    POST,
    PUT,
    DELETE,
    UNKNOWN
} HttpMethod;

typedef struct {
    HttpMethod method;
    char *http_version;
    char *path;
    char *body;
    HashMap *headers;
} HttpRequest;

HttpRequest *createHttpRequest(char *buf, size_t buf_size);
void parseRequestLine(HttpRequest *request, char *line);
void addHeaders(char *line, HttpRequest *request);
void destroyHttpRequest(HttpRequest *request);
HttpMethod stringToHttpMethod(char *method);


#endif //CODECRAFTERS_HTTP_SERVER_C_HTTPPARSER_H
