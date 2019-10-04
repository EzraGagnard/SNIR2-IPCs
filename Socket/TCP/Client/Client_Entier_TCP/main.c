/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mc
 *
 * Created on 10 septembre 2019, 11:37
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

    clientSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == -1) {
        printf("pb socket : %s\n", strerror(errno));
        exit errno;
    }
    // init de informationsServeur
    // IP, port, type
    informationsServeur.sin_family = AF_INET;
    informationsServeur.sin_port = htons(5555);
    informationsServeur.sin_addr.s_addr = inet_addr("172.18.58.147");
    monEntier = 42;
    memset(&informationsServeur.sin_zero, 0, sizeof (informationsServeur.sin_zero));
    connect(clientSocket,(struct sockaddr *) &informationsServeur,sizeof(informationsServeur));
    write(clientSocket,&monEntier,sizeof (monEntier)); 
    read(clientSocket,&entierDuServeur,sizeof(entierDuServeur));
    printf("Réponse du serveur: %d\n", entierDuServeur);
 close(clientSocket);
    return (EXIT_SUCCESS);
}

