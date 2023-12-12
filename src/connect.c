// Make a simple 'telnet' type connection the IRC server using unecrypted TCP - Later this will need another function with SSL for SSL-enabled servers.

#include <stdio.h>
#include <strings.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int connect_server(char *IP_ADDR, uint16_t PORT) {
    // Use sockets to connect to any given server.
    struct sockaddr_in addr; // Initialise the socket   

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a file descriptor of the socket.
    if (sockfd == -1) { // Check for faliure
        perror("Failed to create socket.");
        return 0;
    }
    
    // bzero(&addr, sizeof(addr)); // I don't think this is needed.
    addr.sin_family = AF_INET; // Set IPv4
    addr.sin_port = htons(PORT); // htons is a specific data type for a port.
    if (inet_pton(AF_INET, IP_ADDR, &addr.sin_addr) <= 0) { // Convert the IP to a binary form and check for faliure.
        perror("Failed to convert IP.");
        return 0;
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) { // Attempt to connect the socket, and check for faliure.
        perror("Failed to connect to server.");
        return 0;
    }
    return sockfd; // Return the configured and connected file descriptor.
}