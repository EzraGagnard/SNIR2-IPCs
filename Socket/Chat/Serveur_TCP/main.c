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


    
int main(int argc, char** argv) {
  
     
    int socketServeur;
    struct sockaddr_in informationsServeur;
    struct sockaddr_in informationsClient;
    char protocoleHttp[2048];
    char getDuClient[2048];
    int retourBind;
    int retourListen;
    int socketClient;
    int retourWrite;
    int retourRead;
    int tailleAdr;
    char html[2048];
    strcpy (html,"<html><h1>TEST</h1></html>");
    int taillehtml = strlen(html);
    char taillehtmlc = (char)taillehtml;
     strcpy (protocoleHttp,"HTTP/1.1 200 OK\nContent-Length: ");
  //  strcat(protocoleHttp,taillehtmlc);
     strcat(protocoleHttp,"\nContent-Type: text/html\n\n");
     strcat(protocoleHttp,"<html><h1>TEST</h1></html>");
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
        memset(getDuClient,0,2048);
        retourRead = read(socketClient,&getDuClient,sizeof(getDuClient));
        if(retourRead==-1){
            printf("pb lecture : %s\n",strerror(errno));
            exit errno;
        }
        printf("%s\n",getDuClient);
  printf("Message : %s",protocoleHttp);
        
        retourWrite = write(socketClient,&protocoleHttp,2048);
        if(retourWrite==-1){
            printf("pb écriture : %s\n",strerror(errno));
            exit errno;
        }
     
    }while(1);
    close(socketServeur); 
     
    
    return (EXIT_SUCCESS);
}