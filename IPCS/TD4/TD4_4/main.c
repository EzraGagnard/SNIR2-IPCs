#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXBUFF 255

void traitement(int sig) {
    (void) signal(SIGUSR1, traitement);
    printf("le pid est :%d\n", getpid());
}

int main() {
    // P1
    (void) signal(SIGUSR1, traitement);
    int nbOctets;
    int descTube[2];
    char buffer[MAXBUFF];
    pid_t pidP2, pidP3, pid;
    memset(buffer, '\0', MAXBUFF);

    if (pipe(descTube) == 0) {
        pidP2 = fork();
        if (pidP2 == -1) {
            fprintf(stderr, "Pb de fork");
            exit(EXIT_FAILURE);
        } else { // le fork est bon
            if (pidP2 > 0) { // P1
               
                nbOctets = read(descTube[0], buffer, MAXBUFF); //lecture
                printf("P1 lit: %s\n", buffer);
                 kill(pidP2, SIGUSR1);
                kill(pidP3, SIGUSR1);

            } else { // P2
                pidP3 = fork();
                if (pidP3 > 0) { //P2


                } else { // P3

                    nbOctets = write(descTube[1], getpid(), sizeof (pidP3)); //Ecriture


                }

            }
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}