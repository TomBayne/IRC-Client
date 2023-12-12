// This file includes the functions for the IRC Client

// Function to handle the connection to an IRC server
int connect_server(char *IP_ADDR, int PORT); // Takes in an IP address as an array of chars, and a port as int.

// Function to receive a message from an IRC server.
char *rx_msg(int socket_fd); // Takes a file descriptor of a socket as an int.

// Function to send a message to an IRC server.
void tx_msg(int socket_fd, char *message); // Takes the socket file descriptor as int, and the message as an array of chars.
