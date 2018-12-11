#include "stdafx.h"

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
                if(message.messageid[0]==0&&message.messageid[1]==0)
                {
                        if((message.code&0x80)==0x80)//precedence of operator is important
                        {
                                printf("\033[31;49;1m●\033[39;49;0m client %d has been shutdown",message.clientid);
                        }
                        else if((message.code&0x80)==0x00)
                        {
                                printf("\033[32;49;1m●\033[39;49;0m client %d is alive",message.clientid);
                        }
                        else
                        {
                        }
                        printf(" at time:"); 
                        for(int i =0;i<8;i++)
                        {
                                if(message. message[i]<0xf)
                                {
                                        printf("0");
                                }
                                printf("%x",message.message[i]);
                        }
                        printf("\n");
                }
                else
                {
                        if((message.code&0x01)==0x00&&(message.code&0x10)==0x00)
                        {
                                printf("\033[32;49;1m●\033[39;49;0m client:%d type:shell\n",message.clientid);
                        }
                        else if(message.code==0x02)
                        {
                        }
                        else if(message.code==0x12)
                        {
                                printf("\033[31;49;1m●\033[39;49;0m client:%d type:cmd error\n",message.clientid);
                        }
                        else if(message.code==0x32)
                        {
                                printf("\033[33;49;1m●\033[39;49;0m client:%d type:too long\n",message.clientid);
                        }
                        printf("%s\n",message.message);
                }
    }


}

