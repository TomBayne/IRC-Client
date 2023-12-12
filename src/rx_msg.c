#include <stdlib.h>
#include <sys/socket.h>

// Function to receive a message from an IRC server.
char *rx_msg(int socket_fd) {
    char *buffer = malloc(sizeof(char) * 512); // RFC1459, max msg length is 512 incl CRLF (510 real chars.)
    recv(socket_fd, buffer, sizeof(buffer), 0);
    return buffer; // Remember to free this on the other end.
}