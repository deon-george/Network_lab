//server
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0},rev[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server listening on port 8080...\n");

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
   
    read(new_socket, buffer, 1024);
    printf("Client says: %s\n", buffer);
    
    
     printf("Server Relistening on port 8080...\n");
new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
     read(new_socket, buffer, 1024);
    //printf("Client says: %s\n", buffer);
     for (int i = strlen(buffer) - 1; i >= 0; i--) {
       int j;
         rev[j++] = buffer[i];
    }
   int j;
    rev[j] = '\0';

    printf("Reversed string: %s\n", rev);
    
    close(new_socket);
    close(server_fd);
    return 0;
}