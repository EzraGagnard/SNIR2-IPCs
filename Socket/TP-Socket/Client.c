/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reel.c
 * Author: ggagnard
 *
 * Created on 17 septembre 2019, 11:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

/*
 * 
 */

int main(int argc, char** argv) {
    int clientSocket;
    struct sockaddr_in informationsServeur;
    int monEntier;
    int entierDuServeur;
    int retourSendto;
    int retourRecvfrom;

    clientSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (clientSocket == -1) {
        printf("pb socket : %s\n", strerror(errno));
        exit errno;
    }
    // init de informationsServeur
    // IP, port, type
    informationsServeur.sin_family = AF_INET;
    informationsServeur.sin_port = htons(2222);
    informationsServeur.sin_addr.s_addr = inet_addr("172.18.58.91");

    memset(&informationsServeur.sin_zero, 0, sizeof (informationsServeur.sin_zero));

    monEntier = 42;
    do{
    retourSendto = sendto(clientSocket, &monEntier, sizeof(monEntier), 0, &informationsServeur,sizeof(informationsServeur));
    if (retourSendto) {

    }
    retourRecvfrom = recvfrom(clientSocket,&entierDuServeur, 255,0,&informationsServeur,sizeof(informationsServeur));
    if (retourRecvfrom) {
        
    }
    monEntier++;
    printf("Réponse du serveur: %d\n", entierDuServeur);
    }while(1);
    return (EXIT_SUCCESS);
}

/*
 
 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>


int main(int argc, char** argv) {
    int clientSocket;
    struct sockaddr_in informationsServeur;
    float monEntier;
    float entierDuServeur;
    int retourSendto;
    int retourRecvfrom;

    clientSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (clientSocket == -1) {
        printf("pb socket : %s\n", strerror(errno));
        exit errno;
    }
    // init de informationsServeur
    // IP, port, type
    informationsServeur.sin_family = AF_INET;
    informationsServeur.sin_port = htons(3333);
    informationsServeur.sin_addr.s_addr = inet_addr("172.18.58.104");

    memset(&informationsServeur.sin_zero, 0, sizeof (informationsServeur.sin_zero));

    monEntier = 42;
   /* while(monEntier < 5){
            retourSendto = sendto(clientSocket, &monEntier, sizeof(monEntier), 0, &informationsServeur,sizeof(informationsServeur));
            sleep(1);
            monEntier+=0.5;
    } */
/*
    retourSendto = sendto(clientSocket, &monEntier, sizeof(monEntier), 0, &informationsServeur,sizeof(informationsServeur));
    if (retourSendto) {

    }
    retourRecvfrom = recvfrom(clientSocket,&entierDuServeur,sizeof(entierDuServeur),0,&informationsServeur,sizeof(informationsServeur));
    if (retourRecvfrom) {
        
    }
    printf("Réponse du serveur: %f\n", entierDuServeur);

    return (EXIT_SUCCESS);
}

*/