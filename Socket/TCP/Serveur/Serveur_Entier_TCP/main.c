/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mc
 *
 * Created on 24 septembre 2019, 10:45
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
 * 
 */

typedef struct{
    unsigned char jour;
    unsigned char mois;
    unsigned short int annee;
    char jourDeLaSemaine[10];	// le jour en toute lettre
}datePerso;
    
int main(int argc, char** argv) {
  
     
    int socketServeur;
    struct sockaddr_in informationsServeur;
    struct sockaddr_in informationsClient;
    char protocoleHttp[255];
    char getDuClient;
    int retourBind;
    int retourListen;
    int socketClient;
    int retourWrite;
    int retourRead;
    int tailleAdr;
   *protocoleHttp = "HTTP/1.1 200 OK\nContent-Length: 3301\nContent-Type: text/html\n<html><h1>TEST</h1></html>";
     printf("Message : %s",protocoleHttp);
    
    socketServeur=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(socketServeur==-1){
        printf("pb socket : %s\n",strerror(errno));
        exit errno;
    }
    // init de informationsServeur avec les infos du serveur
    // IP, port, type
    informationsServeur.sin_family = AF_INET;
    informationsServeur.sin_port = ntohs (8888);
    informationsServeur.sin_addr.s_addr = inet_addr("172.18.58.93");
    
    memset(informationsServeur.sin_zero,0,sizeof(informationsServeur.sin_zero));
    
    retourBind = bind(socketServeur,(struct sockaddr*) &informationsServeur, sizeof(informationsServeur));
    if(retourBind==-1){
        printf("pb bind : %s\n",strerror(errno));
        exit errno;
    }
    
    retourListen = listen(socketServeur,5);
    if(retourListen==-1){
        printf("pb écoute : %s\n",strerror(errno));
        exit errno;
    }
    
    do{
        tailleAdr = sizeof(informationsServeur);
        socketClient = accept(socketServeur,(struct sockaddr*)&informationsServeur, &tailleAdr);
        if(socketClient==-1){
            printf("pb confirmation : %s\n",strerror(errno));
            exit errno;
        }
    
        retourRead = read(socketClient,&getDuClient,sizeof(getDuClient));
        if(retourRead==-1){
            printf("pb lecture : %s\n",strerror(errno));
            exit errno;
        }
        printf("%c",getDuClient);
      //  protocoleHttp=-getDuClient;
        
        retourWrite = write(socketClient,&protocoleHttp,sizeof(protocoleHttp));
        if(retourWrite==-1){
            printf("pb écriture : %s\n",strerror(errno));
            exit errno;
        }
        printf("Message : %s",protocoleHttp);
    }while(1);
    close(socketServeur); 
     
    
    return (EXIT_SUCCESS);
}