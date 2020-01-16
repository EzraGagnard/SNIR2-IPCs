#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXBUFF 255
int main()
{
    // P1
   
    int nbOctets;
    int descTube[2];
      int descTube2[2];
    const char chaine[] = "SALUT FISTON !!!";
    const char chaine2[] = "SALUT PAPA !!!";
    char buffer[MAXBUFF];
    pid_t pid;
    memset(buffer, '\0', MAXBUFF);
    
    if(pipe(descTube) == 0){
        pid = fork(); 
        if(pid == -1) {
            fprintf(stderr,"Pb de fork");
            exit(EXIT_FAILURE);
        }else{ // sinon le fork est bon
            if (pid >0) { // je suis le pere
                //printf("DEBUG %i DEBUG \n\n",descTube[1]);
               nbOctets = write(descTube[1], chaine, strlen(chaine)); //Ecriture
                printf("%d octets ecrits\n",nbOctets);
              
               
            }else{ // je suis le fils
                nbOctets = read(descTube[0], buffer, MAXBUFF); //lecture
                printf("octets lus: %d: %s\n",nbOctets,buffer);
             ;
                exit(EXIT_SUCCESS);
            }
            
    }
        exit(EXIT_SUCCESS);
    }
   
    return 0;
}