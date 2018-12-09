#include "stdafx.h"
#define IPPORT_V4 6789
int port=6789;


char ip[2][16]={"127.0.0.1","127.0.0.1"};
char id[2] = {121,121};
int main(int argc, char** argv) 
{
	int cpid = 0;
	if((cpid=fork())==0)
	{
		waittingforreceive();
	}
	else
	{	
                time_t t;
                msg message;
                inint(&message);
                message.code = 3;
                while(1){
                                fgets (message.message, MESSAGELEN-1, stdin);
                                if(strlen(message.message)==1&&message.message[0]=='\n')
                                {
                                }
                                else
                                {
                                        for(int i = 0 ;i< 2;i++)
                                        {
                                                message.clientid = id[i];
                                                srand((unsigned)time(NULL));
                                                message.messageid[0] = time(0)%254;
                                                message.messageid[1] = rand()%255; 
                                                if(__CAN_NOT_CLOSE__ == isend(ip[i],IPPORT_V4,&message))
                                                {
                                                        continue;
                                                        print_error(__CAN_NOT_CLOSE__);
                                                }
                                        }
                                }
                        }
                wait(&cpid);
                exit(0);
        }
        return (EXIT_SUCCESS);
}
