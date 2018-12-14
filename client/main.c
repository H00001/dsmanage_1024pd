#include "stdafx.h"
#define IPPORT_V4 6789
#define CLILEN_V4 3
int port=6789;


char ip[CLILEN_V4][16]={"127.0.0.1","",""};
char id[CLILEN_V4] = {121,121,123};
int main(int argc, char** argv) 
{
        print_first();
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
                                message.message[strlen(message.message)-1] = 0;
                                if(strlen(message.message)==0||message.message[0]=='\n')
                                {
                                }
                                else
                                {
                                        for(int i = 0 ;i< CLILEN_V4;i++)
                                        {
                                                
                                                message.clientid = id[i];
                                                srand((unsigned)time(NULL));
                                                message.messageid[0] = time(0)%254;
                                                message.messageid[1] = rand()%255; 
                                                if(strlen(ip[0])==0)
                                                {
                                                }
                                                else{
                                                        if(__CAN_NOT_CLOSE__ == isend(ip[i],IPPORT_V4,&message))
                                                        {
                                                                print_error(__CAN_NOT_CLOSE__);
                                                                continue;
                                                        }
                                                }
                                        }
                                }
                        }
                wait(&cpid);
                exit(0);
        }
        return (EXIT_SUCCESS);
}
