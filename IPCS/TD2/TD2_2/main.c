#include <stdio.h>
#include <stdlib.h>
#define NBMAXCAR 255

int main(int argc, char *argv[]) {
    int pid1, pid2;
    char message[NBMAXCAR];
    memset(message, 0, NBMAXCAR); // init message vide
    pid1 = fork();
    if (pid1 == 0) {
        //formatage du message
        sprintf(message, "pid = %d pid du pere = %d", getpid(), getppid());
        boite("boite1", message);

        pid2 = fork();
        if (pid2 == 0) {
            //formatage du message
            sprintf(message, "pid = %d pid du pere = %d", getpid(), getppid());
            boite("boite2", message);

        } else {
            //formatage du message
            sprintf(message, "pid = %d pid du pere = %d", getpid(), getppid());
            boite("boite3", message);

        }
    } else {
        //formatage du message
        sprintf(message, "pid = %d pid du pere = %d", getpid(), getppid());
        boite("boite4", message);

    }
    return EXIT_SUCCESS;
}