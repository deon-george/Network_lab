//client
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char message[1024]; // Buffer for user input

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }

    // --- NEW: Take message from user ---
    printf("Enter message to send: ");
    fgets(message, 1024, stdin);

    send(sock, message, strlen(message), 0);
   // printf("Message sent to server.\n");
    int j=0;
   char buffer[1024] = {0},rev[1024] = {0};
    printf("Message resent from server..... \n");
     for (int i = strlen(message) - 1; i >= 0; i--) {
      //int j;
         rev[j++] = message[i];
    }
    //int j;
    rev[j] = '\0';

    printf(" %s\n", rev);

    close(sock);
    return 0;
}