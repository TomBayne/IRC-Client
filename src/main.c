#include <stdio.h>
#include "../includes/func.h"

int main(void) {
    int PORT = 6667;
    char *IP_ADDR = "127.0.0.1";
    printf("C IRC Client\n");
    connect_server(IP_ADDR, PORT);
}