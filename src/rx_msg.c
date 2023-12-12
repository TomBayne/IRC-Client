#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define BUFFER_SIZE 512 // RFC1459, max msg length is 512 incl CRLF (510 real chars.)

// Function to receive a message from an IRC server.
char *rx_msg(int socket_fd) {
    char *buffer = calloc(sizeof(char) * BUFFER_SIZE, sizeof(char) * BUFFER_SIZE);
    recv(socket_fd, buffer, BUFFER_SIZE, 0);

    // Handle disconnect: place into a function at some point.
    if (strstr(buffer, "ERROR :Closing Link:") != NULL) {
        printf("%s\nServer closed the connection\n", buffer);
        free(buffer);
        exit(0);
    }

    return buffer; // Remember to free this on the other end.
}