#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <winsock2.h>
#include <sys/types.h>  // For Windows, use winsock.h or winsock2.h and sys/types.h
#else
#include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h> // For Linux, use sys/socket.h, netinet/in.h, and netinet/ip.h
#endif

#include <string.h>
#include <errno.h>
#include <unistd.h>

#ifdef _WIN32 // Check if compiling on Windows
#define SO_REUSEPORT_SO_REUSEADDR
#define close closesocket // Windows uses closesocket() instead of close() for sockets
#else
#include <unistd.h> // Include unistd.h for close() on Unix-like systems
    #include <sys/socket.h>
    #define SO_REUSEPORT
#endif


int main()
{
	// Disable output buffering
	setbuf(stdout, NULL);

	// You can use print statements as follows for debugging, they'll be visible when running tests.
	printf("Logs from your program will appear here!\n");

	// Uncomment this block to pass the first stage
	//
	int server_fd, client_addr_len;
	struct sockaddr_in client_addr;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Socket creation failed: %s...\n", strerror(errno));
        return 1;
    }

	// // Since the tester restarts your program quite often, setting REUSE_PORT
	// // ensures that we don't run into 'Address already in use' errors
    int reuse = 1;
    #ifdef SO_REUSEPORT
        // Code that uses SO_REUSEPORT
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) < 0) {
            printf("SO_REUSEPORT failed: %s \n", strerror(errno));
            return 1;
        }
    #else
        // Code for systems where SO_REUSEPORT is not available
        // use SO_REUSEADDR
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
            printf("SO_REUSEPORT failed: %s \n", strerror(errno));
            return 1;
        }
    #endif

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

	 accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
	 printf("Client connected\n");

	 close(server_fd);

	return 0;
}
