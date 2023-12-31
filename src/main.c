#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/func.h"
#define PORT 6667
#define SERVER_IP "108.181.132.149" // The server to connect to

int main(void) {
    int port = PORT;
    char *IP_ADDR = SERVER_IP;
    printf("C IRC Client\n");
    
    int socket = connect_server(IP_ADDR, PORT);
    while (1) {
        char *msg = rx_msg(socket);
        printf("%s", msg);
        free(msg);
        usleep((333 * 1000)); // Throttle message delivery to 3 per second at most
    }
    
}