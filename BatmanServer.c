//tcp server
//mkfifo pipe1
//mkfifo pipe2
#include<stdio.h>
#include<string.h>
 
int main(){
 
   FILE *read_fp;
   FILE *write_fp;
   char msg[100];
   
  printf("Batman Rising.... \n");
  printf("\n");
  while(1){
   // reading in pipe1
   read_fp = fopen("pipe1","r");
   fgets(msg,100,read_fp);
   fclose(read_fp);
   printf("Deadpool: %s",msg);
   
   printf("Batman: ");
   fgets(msg,100,stdin);
   // writing in pipe2
   write_fp = fopen("pipe2","w");
   fprintf(write_fp,"%s",msg);
   fclose(write_fp);
   }
   
   return 0;
 }
   
   
   
   
    
   
   
 
