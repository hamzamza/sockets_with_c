#include <sys/socket.h> // soket(), bind(), listen()...
#include <netinet/in.h> // struct sockaddr_in
#include <unistd.h>     // read(), write()
#include <stdio.h>  
#include <stdlib.h>  // exit(n)
#include <string.h>
#include <arpa/inet.h>
void main(){
struct sockaddr_in srv,clt;
char buff[100];
int pid;
int nb,lg,sock1,sock2;
lg=sizeof(struct sockaddr_in);
strcpy(buff,"bienvenu");
sock1=socket(AF_INET,SOCK_STREAM,0);
//preparation de srv : adresse ecoute
srv.sin_family=AF_INET;
srv.sin_port=htons(2050);
srv.sin_addr.s_addr=INADDR_ANY;
// attacher la socket a l'adresse
bind(sock1,(struct sockaddr *) &srv,sizeof(struct sockaddr_in));
listen(sock1,5);
while(1){
sock2=accept(sock1,(struct sockaddr *) &clt, &lg);
printf("Connection accepted from %s:%d\n", inet_ntoa(clt.sin_addr), ntohs(clt.sin_port));
if((pid = fork()) == 0){
	close(sock1);
	while(1){
write(sock2,buff,100);
nb=read(sock2,buff,100);
buff[nb]='\0';
printf("mess reçu from %s:%d :", inet_ntoa(clt.sin_addr), ntohs(clt.sin_port));
printf("%s \n",buff);
// fgets(buff,100,stdin);
}
}
else{
close (sock2);
}
}
}
