#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    
    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, SERVER_ADDR, &serv_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection failed");
    }

    // Read data from the server
    int n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("Read error");
    }
    buffer[n] = '\0';

    close(sockfd);

    // Compare the received data with the provided password
    if (strcmp(argv[1], buffer) == 0) {
        printf("Password is correct.\n");
    } else {
        printf("Password is incorrect.\n");
    }

    return 0;
}

