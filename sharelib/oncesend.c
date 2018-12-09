#include "oncesend.h"
int isend(unsigned const char * ip,int port,msg *message )
{
        int socket_descriptor;
        struct sockaddr_in address;
        bzero(&address,sizeof(address));
        address.sin_family=AF_INET;
        address.sin_addr.s_addr=inet_addr((const char *)ip);
        address.sin_port=htons(port);
        socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);
        if(socket_descriptor==-1)
        {
                return errno;
        }
        else
        {
                if(-1==sendto(socket_descriptor,message,sizeof(msg),0,(struct sockaddr *)&address,sizeof(address)))
                {
                        return errno;
                }
                else
                {
                        return 0;
                }
       }
}
