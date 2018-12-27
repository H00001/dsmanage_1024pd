#include "udpsocket.h"
int inint__cd23(struct sockaddr_in *sin ,int port )
{
        int socket_descriptor;
        memset(sin,0,sizeof(struct sockaddr_in));
        sin->sin_family=AF_INET;
        sin->sin_addr.s_addr=htonl(INADDR_ANY);
        sin->sin_port=htons(port);
        socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);
        if((socket_descriptor)<0)
        {
                return -1;
        }
        if(bind(socket_descriptor,(const struct sockaddr *)sin,sizeof(*sin)))
        {
                //fail;
                return -2;
        }
        else
        {
                return socket_descriptor;
        }

}

