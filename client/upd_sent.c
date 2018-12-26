#include "stdafx.h"
int isend_m(int socket_descriptor,unsigned const char * ip,int port,msg *message )
{
        struct sockaddr_in address;
        memset(&address,0,sizeof(struct sockaddr_in));
        address.sin_family=AF_INET;
        address.sin_addr.s_addr=inet_addr((const char *)ip);
        address.sin_port=htons(port);
        if(-1==sendto(socket_descriptor,message,sizeof(msg),0,(struct sockaddr *)&address,sizeof(address)))
        {
                return errno;
        }
        else
        {
                return 0;
        }
        return 0;
}
