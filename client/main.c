#include "stdafx.h"
int port=6789;


char ip[2][16]={"127.0.0.1","127.0.0.1"};
char id[2] = {121,121};
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
                message.clientid = 121;
                message.messageid[0] = time(0)%254;
                message.code = 3;
                message.messageid[1] = (time(0)/100) %254;
                struct sockaddr_in address;
                bzero(&address,sizeof(address));
                while(1){
                        fgets (message.message, MESSAGELEN-1, stdin);
                        if(strlen(message.message)==1&&message.message[0]=='\n')
                        {
                        }
                        else
                        {
                                isend("127.0.0.1",6789,&message);
                        }
        }
        close(socket_descriptor);
        printf("Messages Sent,terminating\n");
        wait(&cpid);
        exit(0);
    }
        return (EXIT_SUCCESS);
}
