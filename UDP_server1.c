#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
int sock;
char buffer[1024];
struct sockaddr_in server,client;
socklen_t client_len;

//creating UDP socket
sock=socket(AF_INET,SOCK_DGRAM,0);

//server address
server.sin_family=AF_INET;
server.sin_port=htons(8080);
server.sin_addr.s_addr = INADDR_ANY;

//bind socket to port 8080
bind(sock,(struct sockaddr*)&server,sizeof(server));

printf("UDP Server listening on port 8080...\n");

client_len = sizeof(client);
//receive msg from client

recvfrom(sock,buffer,sizeof(buffer),0,(struct sockaddr*)&client,&client_len);

 printf("Client says: %s\n", buffer);
char reply[] = "Message received!";
    sendto(sock, reply, strlen(reply), 0,
           (struct sockaddr*)&client, client_len);

    close(sock);
    return 0;
}
