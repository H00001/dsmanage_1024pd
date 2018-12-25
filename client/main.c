#include "stdafx.h"

char ip[CLILEN_V4][16]={"127.0.0.1","192.168.1.103",""};
char id[CLILEN_V4] = {121,120,123};
void message_handle_input(int *cpid,unsigned short *mids);
int main(int argc, char** argv) 
{
        /**
         * test code 
         */
        unsigned short mids[20];
        /**
         * end
         */

//        print_first();
	int cpid = 0;
	if((cpid=fork())==0)
	{
		waittingforreceive();
	}
	else
	{	
                message_handle_input(&cpid,mids);
        }
        return (EXIT_SUCCESS);
}
//int sendMsg_002b(msg *__obj__)
//{
        


//}
void message_handle_input(int *cpid,unsigned short *mids)
{

        msg message;
        inint(&message);
        while(1){
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
                                        message.code = REQUEST|ISALIVE;
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
                        time_t t;
                        for(int i = 0 ;i< CLILEN_V4;i++)
                        {

                                message.code = REQUEST|SHELL;
                                message.clientid = id[i];
                                srand((unsigned)time(NULL));
                                message.messageid[0] = time(0)%254;
                                /**
                                 * test code
                                 *
                                */
                                message.messageid[1] = rand()%255; 
                                mids[0] = message.messageid[0] << 8;
                                mids[0] += message.messageid[1];
                                if(strlen(ip[0])==0)
                                {
                                }
                                else
                                {
                                        if(__CAN_NOT_CLOSE__ == isend(ip[i],IPPORT_V4,&message))
                                        {
                                                print_error(__CAN_NOT_CLOSE__);
                                                continue;
                                        }
                                }
                        }
                }
        }
        wait(cpid);
        exit(0);
}
