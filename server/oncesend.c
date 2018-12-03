#include "oncesend.h"

int isend(char * ip,int port,msg *message )
{
    printf("\nsend message\n");
    int socket_descriptor;
    struct sockaddr_in address;
    bzero(&address,sizeof(address));
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr(ip);//这里不一样
    address.sin_port=htons(port);
    socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);
    sendto(socket_descriptor,message,sizeof(msg),0,(struct sockaddr *)&address,sizeof(address));
    return 0;
}
