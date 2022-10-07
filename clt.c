#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>  //gethostbyname()
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * argv[]){
char buff[100];
int nb,sock;
struct sockaddr_in srv; //clt se connectera a ce serveur
struct hostent * hp; //retour de gethostbyname()
sock=socket(AF_INET,SOCK_STREAM,0);
hp=gethostbyname(argv[1]);
srv.sin_family=AF_INET;
srv.sin_port=htons(atoi(argv[2]));
srv.sin_addr.s_addr=((struct in_addr *) (hp->h_addr))->s_addr;
connect(sock, (struct sockaddr *) &srv,sizeof(struct sockaddr_in));
while(1){
nb=read(sock,buff,100);
buff[nb]='\0';
printf(" %s \n",buff);
fgets(buff,100,stdin);
write(sock,buff,100);
if (strncmp(buff, "exit",4)==0) break;
}
}




