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
        if(close(socket_descriptor)==0)
        {
                return 0;
        }
        else
        { 
         return 214;
        }
}


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
int inint__cd23(struct sockaddr_in *sin ,int port)
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

