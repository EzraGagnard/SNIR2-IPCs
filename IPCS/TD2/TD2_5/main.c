// TD2 Q5
// CETTE QUESTION EST IMPOSSIBLE WAITPID() ATTEND UN PROCESSUS FILS PAS DARON
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#define NBMAXCAR 255

int main(int argc, char *argv[]) {
    int pid;
    int status = 0;
    int pidf,pidDaron;
    char message[NBMAXCAR];
    memset(message, 0, NBMAXCAR); // init message vide

    //p1
    pid = fork();
    if (pid == 0) { //p2
        pidf = waitpid(getppid(),&status,0);
        sprintf(message, "pid = %d pid du pere = %d", getpid(), getppid());
        boite("p2", message);

    } else { // p1

        sprintf(message, "pid = %d pid du pere = %d", getpid(), getppid());
        boite("p1", message);

    }
    return EXIT_SUCCESS;
}