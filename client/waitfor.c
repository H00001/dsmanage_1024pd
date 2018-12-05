#include "waitfor.h"

int inint__cd23(int *socket_descriptor, struct sockaddr_in *sin)
{
    int sin_len;
    bzero(sin,sizeof(struct sockaddr_in));
    sin->sin_family=AF_INET;
    sin->sin_addr.s_addr=htonl(INADDR_ANY);
    sin->sin_port=htons(1024);
    sin_len=sizeof(*sin);
    *socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);
    if(*socket_descriptor<0)
    {
            return -1;
    }
   if(bind(*socket_descriptor,(const struct sockaddr *)sin,sizeof(*sin)))
   {
            return -2;
   }
   return sin_len;

}

void waittingforreceive()
{
        int sin_len;
        msg message;
        unsigned char buffer[MESSAGEIDLEN+OPTIONLEN+MESSAGELEN+3];
        int socket_descriptor;
        struct sockaddr_in sin;
        sin_len = inint__cd23(&socket_descriptor,&sin);
        while(1)
        {
                recvfrom(socket_descriptor,&buffer,sizeof(buffer),0,(struct sockaddr *)&sin,&sin_len);
                changeTomsg(buffer,&message);
                printf("\tclientid:%d\n",message.clientid);
                printf("\tmessageid:%d%d\n",message.messageid[0],message.messageid[1]);
                if(message.messageid[0]==0&&message.messageid[1]==0)
                {
                        if(message.code&0x08==0x08)
                        {
                                printf("\ttype:client has been shutdown\n");
                        }
                        else if(message.code&0x08==0x00)
                        {
                                printf("\ttype:client is alive\n");
                        }

                }
                else
                {
                        if((message.code&0x01)==0x00&&(message.code&0x10)==0x00)
                        {
                                printf("\ttype:resopnse shell\n");
                        }
                        if(message.code==0x02)
                        {
                        }
                        if(message.code==0x12)
                        {
                                printf("\ttype:error cmd error\n");
                        }
                        if(message.code==0x32)
                        {
                                printf("\ttype:message too long\n");
                        }
                        printf("\tresponse:%s",message.message);
                }
    }


}

