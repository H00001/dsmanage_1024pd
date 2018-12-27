#include "stdafx.h"

char ip[CLILEN_V4][16]={"127.0.0.1","39.106.46.179","123.207.72.126"};
char id[CLILEN_V4] = {121,128,123};
int main(int argc, char** argv) 
{
        struct sockaddr_in sin;
        int s_direscpt = inint__cd23(&sin,1024);
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
		waittingforreceive(s_direscpt,&sin);
	}
	else
	{	
                message_handle_input(s_direscpt,&cpid,mids);
        }
        return (EXIT_SUCCESS);
}
//int sendMsg_002b(msg *__obj__)
//{
        


//}
void message_handle_input(int s_direscpt,int *cpid,unsigned short *mids)
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
                                        if(__CAN_NOT_CLOSE__ == isend_m(s_direscpt,ip[i],IPPORT_V4,&message))
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
                                        if(__CAN_NOT_CLOSE__ == isend_m(s_direscpt,ip[i],IPPORT_V4,&message))
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
