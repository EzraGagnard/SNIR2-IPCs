#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXBUFF 255

int main() {
    // P1

    int nbOctets;
    int descTube[2];
    int descTube2[2];
    const char chaine[] = "SALUT FISTON !!!";
    const char chaine2[] = "SALUT PAPA !!!";
    char buffer[MAXBUFF];
    pid_t pid;
    memset(buffer, '\0', MAXBUFF);

    if (pipe(descTube) == 0 && pipe(descTube2) == 0) {
            pid = fork();
            if (pid == -1) {
                fprintf(stderr, "Pb de fork");
                exit(EXIT_FAILURE);
            } else { // le fork est bon
                if (pid > 0) { // je suis le pere

                    nbOctets = write(descTube[1], chaine, strlen(chaine)); //Ecriture

                    nbOctets = read(descTube2[0], buffer, MAXBUFF); //lecture
                    printf("le pere lit: %s\n", buffer);

                } else { // je suis le fils
                    nbOctets = read(descTube[0], buffer, MAXBUFF); //lecture
                    printf("le fils lit: %s\n", buffer);
                    nbOctets = write(descTube2[1], chaine2, strlen(chaine)); //Ecriture
                }

            }
            exit(EXIT_SUCCESS);
    }

    return 0;
}





