#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    char message[1024], buffer[1024];
    struct sockaddr_in server;
    socklen_t server_len;

    // Create UDP socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    // Server address
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.0");

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    // Send message to server
    sendto(sock, message, strlen(message), 0,
           (struct sockaddr*)&server, sizeof(server));

    // Receive response from server
    server_len = sizeof(server);
    recvfrom(sock, buffer, sizeof(buffer), 0,
             (struct sockaddr*)&server, &server_len);

    printf("Server reply: message received");

    close(sock);
    return 0;
}

