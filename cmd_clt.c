#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
void main(){
int sock, lg,nb;
char buff[100];
FILE *fd;
struct sockaddr_in srv, clt;
lg=sizeof(struct sockaddr_in);
sock=socket(AF_INET,SOCK_STREAM,0);
srv.sin_family=AF_INET;
srv.sin_port=htons(3000);
srv.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(sock,(struct sockaddr *) &srv, lg);
printf("entrer la cmd a executer a distance \n");
fgets(buff,100,stdin);
write(sock,buff,100);
close(0);
dup(sock);
while(fgets(buff,100,stdin)!=NULL){
printf("%s \n",buff);
}
}













