// TD3 Q2
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// fonction de traitement du signal SIGUSR1
void traitement(int sig)
{
	(void) signal(SIGUSR1, traitement);
	printf("le pid est %d\n", getpid());
}


int main(int argc, char *argv[])
{
	int pid,pidP1;
	(void) signal(SIGUSR1, traitement);	// rederoutage des signaux SIGUSR1
	// P1
        pidP1 = getpid();						
        pid = fork();
            
		if (pid == 0)// P2
		{
                    pid = fork();
                    if(pid == 0) // P3
                    {
                       
			kill(getppid(), SIGUSR1);
			
                    } else{ // P2
                        pause();
                        pause();
		
                    }
                                     
		}
		else		// P1
		{
                    kill(pid,SIGUR1);
		}
	

	return EXIT_SUCCESS;
}