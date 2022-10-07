#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
void main(){
int sock1, sock2,lg,nb;
char buff[100];
FILE *fd;
struct sockaddr_in srv, clt;
lg=sizeof(struct sockaddr_in);
sock1=socket(AF_INET,SOCK_STREAM,0);
srv.sin_family=AF_INET;
srv.sin_port=htons(3000);
srv.sin_addr.s_addr=inet_addr("127.0.0.1");
bind(sock1, (struct sockaddr *)&srv,lg);
listen(sock1, 5);
sock2=accept(sock1,(struct sockaddr *) &clt, &lg);
nb=read(sock2,buff,100);
buff[nb]='\0';
close(1);
dup(sock2);
close(sock2);
system(buff);
}
















