#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> // For Linux, use sys/socket.h, netinet/in.h, and netinet/ip.h

#include <string.h>
#include <errno.h>
#include <unistd.h>


#include "headers/hashmap.h"
#include "headers/httpparser.h"
//#define SO_REUSEPORT
#define BUFFER_SIZE 4096
#define OUTPUT_BUFFER_SIZE 8192


void printHashMap(HashMap *headers);

int main()
{

	// You can use print statements as follows for debugging, they'll be visible when running tests.
	printf("Logs from your program will appear here!\n");

	// Uncomment this block to pass the first stage
	//
    int server_fd;
	int client_addr_len;
	struct sockaddr_in client_addr;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Socket creation failed: %s...\n", strerror(errno));
        return 1;
    }
    // Since the tester restarts your program quite often, setting REUSE_PORT
    // ensures that we don't run into 'Address already in use' errors

    int reuse = 1;
    // Code that uses SO_REUSEPORT
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) < 0)
    {
        printf("SO_REUSEPORT failed: %s \n", strerror(errno));
        return 1;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(4221);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) != 0) {
        printf("Bind failed: %s \n", strerror(errno));
        return 1;
    }

	 int connection_backlog = 5;
	 if (listen(server_fd, connection_backlog) != 0) {
	 	printf("Listen failed: %s \n", strerror(errno));
	 	return 1;
	 }

	 printf("Waiting for a client to connect...\n");
	 client_addr_len = sizeof(client_addr);

	 int client_socket_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
	 printf("Client connected\n");

     char buffer[BUFFER_SIZE];
     int bytes_read = recv(client_socket_fd, buffer, sizeof(buffer), 0);
     printf("Bytes received: %d, message: %s", bytes_read, buffer);

     HttpRequest *request = createHttpRequest(buffer, bytes_read);
     printf("Received Method: %u\t Received Path: %s\t Received Version: %s\n",
                            request->method, request->path, request->http_version);

     printHashMap(request->headers);

     char response[1024] = {0};
     if(strcmp(request->path, "/") == 0){
         printf("inside 200 ok\n");
         strcpy(response, "HTTP/1.1 200 OK\r\n\r\n");
     }
     else {
         printf("inside 404 not found\n");
         strcpy(response, "HTTP/1.1 404 Not Found\r\n\r\n");
     }


     send(client_socket_fd, response, sizeof(response), 0);
     close(server_fd);
     destroyHttpRequest(request);
	 return 0;
}

void printHashMap(HashMap *map) {
    if (map == NULL) return;

    // Iterate over all buckets
    for (int i = 0; i < map->capacity; i++) {
        Entry *current = map->buckets[i];
        while (current != NULL) {
            printf("Key: %s, Value: %s\n", (char *)current->key, (char *)current->value); // Assuming keys are strings
            current = current->next;
        }
    }
}

//char* parseResponse(HttpRequest *request){
//    char response[OUTPUT_BUFFER_SIZE];
//
//    return response;
//}
