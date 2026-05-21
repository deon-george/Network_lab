#include <stdio.h>
#include <unistd.h>

int main() {

    char *args[] = {"ls", "-l", NULL};

    execv("/bin/ls", args);

    printf("This line will not execute if execv works");

    return 0;
}
