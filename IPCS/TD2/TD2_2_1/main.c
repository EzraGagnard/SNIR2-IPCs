// TD2 Q2
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#define NBMAXCAR 255

int main(int argc, char *argv[]) {
    int pid;
    int waiti;
    int status = 0;
    char message[NBMAXCAR];
    memset(message, 0, NBMAXCAR); // init message vide

    //p1
    pid = fork();
    if (pid == 0) { //p2
        sprintf(message, "pid = %d pid du pere = %d", getpid(), getppid());
        boite("p2", message);

    } else { // p1
        pid = fork();
        if (pid == 0) { //p3
            sprintf(message, "pid = %d pid du pere = %d", getpid(), getppid());
            boite("p3", message);
        } else { //p1
            sprintf(message, "pid = %d pid du pere = %d", getpid(), getppid());
            boite("p1", message);
        }

        waiti = wait(&status);
    }
    return EXIT_SUCCESS;
}