#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/func.h"

int main(void) {
    int PORT = 6667;
    char *IP_ADDR = "109.74.200.93";
    printf("C IRC Client\n");
    
    int socket = connect_server(IP_ADDR, PORT);
    while (1) {
        char *msg = rx_msg(socket);
        printf("%s", msg);
        free(msg);
    }
    
}