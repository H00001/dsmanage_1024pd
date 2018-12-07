#include "stdafx.h"
static twc tc;
int pdt[PDTLEN]; //children process discription table

int __main__init()
{
        memset(&tc,0,sizeof(tc));
        memset(&pdt,0,sizeof(int)*PDTLEN); //inint pdt
        signal(SIGCHLD,&signalHandel);  //reigster the function that deal with defunct process
	signal(SIGINT,&signalHandel);  //reigster the function that deal with ctrl_c request
        return  readconfig("wd1024.conf",&tc);
}


int main() {
        int erro = __main__init();
        int sin_len;
	int cli_pro_id;
        int socket_descriptor;
        struct sockaddr_in sin;
        if(erro!=0)
        {
                print_error(erro);
                exit(-1);
        }
        unsigned char buffer[MESSAGEIDLEN+OPTIONLEN+MESSAGELEN+3];
        sin_len = inint__cd23(&socket_descriptor,&sin,tc.lport);
        if(sin_len <0)
        {
                if(sin_len==-2)
                {
                        print_error(__PORT_HAS_BEEN_USE__);
                }
	        exit(-1);
        }
        printf("Waiting for data form server \n");
        
        sendConIno_(tc.server_v4[0],tc.sport,0,tc.client_id);
        while(1)
        {
                recvfrom(socket_descriptor,&buffer,sizeof(buffer),0,(struct sockaddr *)&sin,&sin_len);
		if(0==(cli_pro_id=fork())){
			message_deal_Hander(buffer);
			return 0;
		}
		else
		{
                        int widz = 0;
                        for(;widz<PDTLEN;widz++){
                                if(pdt[widz]==0)
                                {
                                        pdt[widz] = cli_pro_id;
                                        break;
                                }
                        }
                        if(widz == PDTLEN)
                        {
                                kill(cli_pro_id,SIGKILL);
                        }

			printf("\nprocess:%d deal the message\n",cli_pro_id);
		}
    	}
        close(socket_descriptor);
        exit(0);
        return (EXIT_SUCCESS);
}

void signalHandel(int signo) {
	//the main use is deal with the defunct process
	if(signo==SIGCHLD){
                //if(msgs==5)
                //{/
                          int childStatus;
                          for(int i = 0;i<10;i++){
                                  if(pdt[i]!=0)
                                  {
                                        if(waitpid(pdt[i], &childStatus, WNOHANG)==pdt[i])
                                          {
                                                  printf("process:%d has been collection\n",pdt[i]);
                                                  pdt[i]=0;
                                          }
                                  }
                        }
	}
	else if(signo==2)
	{
                sendConIno_(tc.server_v4[0],tc.sport,1,tc.client_id);
		exit(1);
	}
    	return;

}
int message_deal_Hander(unsigned char * buffer)
{
	msg message;
        inint(&message);
        unsigned char resultbuffer[MESSAGELEN];
	changeTomsg(buffer,&message);
        if(strlen(message.message) == 1&& message.message[0]=='\n')
        {
                 return 0;
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
			printf("\ttype:%s]\n","shell\n"); 
			writeMessage(&message,resultbuffer);
		}
		else if((message.code&0x02)==0)
		{

      		}
		if(isend(tc.server_v4[0],tc.sport,&message)!=0)
		{
			print_sw(DEBUG,PUTERR,"\nerror\n");
		}
	}
	return 0;

}
