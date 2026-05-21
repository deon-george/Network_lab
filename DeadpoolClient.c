//tcp client
//mkfifo pipe1
//mkfifo pipe2
#include <stdio.h>
#include <string.h>

int main() {

    FILE *read_fp;
    FILE *write_fp;

    char msg[100];
    printf("Deadpool is Ready\n");
    printf("\n");

    while (1) {

        // client send
        printf("Deadpool: ");
        fgets(msg, 100, stdin);
        // writing in pipe1
        write_fp = fopen("pipe1", "w");
        fprintf(write_fp, "%s", msg);
        fclose(write_fp);

        // reading in pipe2
        read_fp = fopen("pipe2", "r");
        fgets(msg, 100, read_fp);
        fclose(read_fp);

        printf("Batman: %s", msg);
    }

    return 0;
}
