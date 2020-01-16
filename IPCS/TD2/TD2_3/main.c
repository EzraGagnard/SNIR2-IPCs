// TD2 Q3 & Q4
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#define NBMAXCAR 255

int main(int argc, char *argv[]) {
    int pid;
    int status = 0;
    int pidf,pidf1;
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
            pidf = wait(&status);
            
            pidf1 = wait(&status); // Q4
            
            sprintf(message, "P1 le fils pid = %d est mort et l'autre pid = %d est aussi mort GROS RIP ducoup",pidf,pidf1); //Q4
            boite("p1", message);
        }
        
    }
    return EXIT_SUCCESS;
}