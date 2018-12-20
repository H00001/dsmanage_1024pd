#include "stdafx.h"
#define IPPORT_V4 6789
#define CLILEN_V4 3
int port=6789;


char ip[CLILEN_V4][16]={"127.0.0.1","192.168.1.103",""};
char id[CLILEN_V4] = {121,120,123};
int main(int argc, char** argv) 
{
        //print_first();
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
                while(1){
                                //printf("sh #:");
                                //fflush(stdout);

                                fgets (message.message, MESSAGELEN-1, stdin);
                                message.message[strlen(message.message)-1] = 0;
                                if(strlen(message.message)==0||message.message[0]=='\n')
                                {
                                }
                                
                                else if(message.message[0]=='s'&&
                                        message.message[1]=='t'&&
                                        message.message[2]=='d'&&
                                        message.message[3]==':')
                                {

                                        if(strcmp(message.message+4,"who")==0)
                                        {
                                                
                                                for(int i = 0 ;i< CLILEN_V4;i++)
                                               
                                               {                           
                                                        message.clientid = id[i];
                                                        message.code = 0x01|0x04;
                                                        if(strlen(ip[0])==0)
                                                        {
                                                        }
                                                        if(__CAN_NOT_CLOSE__ == isend(ip[i],IPPORT_V4,&message))
                                                        {
                                                                print_error(__CAN_NOT_CLOSE__);
                                                                continue;
                                                        }

                                                }
                                        }
                                }
                                else
                                {
                                        for(int i = 0 ;i< CLILEN_V4;i++)
                                        {
                                                
                                                message.code = 0x01|0x02;
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
//int sendMsg_002b(msg *__obj__)
//{
        


//}
