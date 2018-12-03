#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include "fcntl.h"
#include <sys/types.h>
#include <sys/wait.h>
#include<math.h>
#include "waitfor.h"
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include<time.h>
int port=6789;
int main(int argc, char** argv) {

	int cpid = 0;
	if((cpid=fork())==0)
	{
		waittingforreceive();
	}
	else
	{	
    int socket_descriptor; 
    int iter=0;
    time_t t;

    msg message;
    inint(&message);
    message.clientid = 1;
    message.messageid[0] = time(0)%254;
    message.code = 3;
    message.messageid[1] = (time(0)/100) %254;

    fgets (message.message, 999, stdin);
    struct sockaddr_in address;

    bzero(&address,sizeof(address));
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr("127.0.0.1");//这里不一样
    address.sin_port=htons(port);
    socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);
    sendto(socket_descriptor,&message,sizeof(message),0,(struct sockaddr *)&address,sizeof(address));

    close(socket_descriptor);
    printf("Messages Sent,terminating\n");

    wait(&cpid);
    exit(0);
	}
    return (EXIT_SUCCESS);
}
