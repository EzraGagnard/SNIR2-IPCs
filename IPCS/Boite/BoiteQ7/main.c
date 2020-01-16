#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    /*
     if ( pid1 == 0 )
          {
                  boite("boite1","pid1=0");
                  pid2 = fork();
     else  {
   
     */
    int pid;


    //    // p1
    //    pid = fork();
    //    if (pid == 0) { // p3
    //        //
    //
    //        pid = fork();
    //        if (pid == 0) { // p5
    //         pid = fork();
    //            
    //         
    //         if (pid == 0) { // p6
    //
    //            
    // 
    //        } else { //p5
    //        printf("pid=%d ppid=%d\n", getpid(), getppid());
    //        boite("p5","pid=0");
    //        } 
    // 
    //        } else { //p3
    //        printf("pid=%d ppid=%d\n", getpid(), getppid());
    //        boite("p3","pid=0");
    //        }
    //
    //
    //
    //    } else { //p1
    //        printf("pid=%d ppid=%d\n", getpid(), getppid());
    //        boite("p1", "pid<>0");
    //    }


    pid = fork();
    //p1
    if (pid == 0) { //p3
        pid = fork();
        if (pid == 0) { //p2
            boite("p2", "pid=0");
            printf("P2 : pid=%d ppid=%d\n", getpid(), getppid());
        } else { //p3
            if (pid == 0) { //p4
                boite("p4", "pid=0");
                printf("P4 : pid=%d ppid=%d\n", getpid(), getppid());
            } else { //p3
                pid = fork();

                if (pid == 0) { //p5
                    pid = fork();
                    if (pid == 0) {
                        pid = fork();
                        if(pid==0){ //
                            
                        }else{
                            
                        }
                        
                        
                        
                        
                    } else { //p5
                        boite("p5", "pid=0");
                        printf("P5 : pid=%d ppid=%d\n", getpid(), getppid());
                    }





                } else { //p3
                    boite("p3", "pid=0");
                    printf("P3 : pid=%d ppid=%d\n", getpid(), getppid());
                }

            }
        }



    } else //p1
    {
        boite("p1", "pid=0");
        printf("P1 : pid=%d ppid=%d\n", getpid(), getppid());
    }


    return EXIT_SUCCESS;
}