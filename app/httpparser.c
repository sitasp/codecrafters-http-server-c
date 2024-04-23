//
// Created by ASUS on 22-04-2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/hashmap.h"
#include "headers/httpparser.h"
#include "headers/stringutils.h"
#include "ctype.h"

#define MAX_HTTP_VERSION 10
#define MAX_HEADERS 20
#define MAX_HEADER_NAME_LEN 50
#define MAX_HEADER_VALUE_LEN 1000
#define MAX_BODY_LEN 4096
#define MAX_PATH_LEN 100

HttpRequest *createHttpRequest(char *buf, size_t buf_size) {
    HttpRequest *request = (HttpRequest *)malloc(sizeof(HttpRequest));
    if(request == NULL){
        return NULL;
    }
//    request->headers = (HashMap *)malloc(sizeof(HashMap));
//    request->body = (char *)malloc

    char *CRLF = "\r\n";
    int total_lines = 0;
    printf("Input string - %s", buf);
    char **lines = split(buf, CRLF, &total_lines);

    printf("total lines - %d\n", total_lines);
    for(int i=0;i<total_lines;i++){
        printf("strings separated by CRLF is - %s\n", lines[i]);
    }

    for(int i=0;i<total_lines;i++){
        if(i == 0){
            parseRequestLine(request, lines[i]);
            continue;
        }
        addHeaders(lines[i], request);
    }
    return request;
}

void parseRequestLine(HttpRequest *request, char *line) {
    char *space = " ";
    int element_count = 0;
    char **elements = split(line, space, &element_count);
    for(int i=0; i<element_count; i++){
        switch(i){
            case 0:
                request->method = stringToHttpMethod(elements[i]);
                break;
            case 1:
                request->path = (char *)malloc(MAX_PATH_LEN * sizeof(char));
                strcpy(request->path, elements[i]);
                break;
            case 2:
                request->http_version = (char *)malloc(MAX_HTTP_VERSION * sizeof(char));
                strcpy(request->http_version, elements[i]);
                break;
            default:
                break;
        }
    }
}

void addHeaders(char *line, HttpRequest *request) {
    char *colon = ":";
    int count = 0;
    char **elements = split(line, colon, &count);
    if(request->headers == NULL){
        request->headers = createHashMap(4096, 4096, compareString, hashString);
    }
    if(count == 2){
        insert(request->headers, elements[0], trimString(elements[1]));
    }
    else if(count > 2){
        char *res = "";
        for (int i = 1; i < count; i++) {
            // Calculate the new length of the concatenated string
            size_t newLength = strlen(res) + strlen(elements[i]) + 1; // +1 for the null terminator

            // Allocate memory for the new concatenated string
            char *newRes = (char *)malloc(newLength);
            if (newRes == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            strcpy(newRes, res);
            if(i > 1){
                strcat(newRes, ":");
            }
            strcat(newRes, elements[i]);
            res = newRes;
        }
        insert(request->headers, elements[0], trimString(res));
        free(res);
    }
}

void destroyHttpRequest(HttpRequest *request) {
    if(request == NULL) return;
    if(request->headers!=NULL){
        free(request->headers);
    }
    if(request->http_version!=NULL){
        free(request->http_version);
    }
    if(request->path!=NULL){
        free(request->path);
    }
    if(request->body!=NULL){
        free(request->body);
    }
    free(request);
}

HttpMethod stringToHttpMethod(char *method) {
    toLower(method);
    printf("method is: %s\n", method);
    if (strcmp(method, "get") == 0) {
        return GET;
    } else if (strcmp(method, "post") == 0) {
        return POST;
    } else if (strcmp(method, "put") == 0) {
        return PUT;
    } else if (strcmp(method, "delete") == 0) {
        return DELETE;
    } else {
        // Handle unknown method
        fprintf(stderr, "Unknown HTTP method: %s\n", method);
        return UNKNOWN; // Or any other error indication
    }
}