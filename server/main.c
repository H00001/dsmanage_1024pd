#include "stdafx.h"
#define PDTLEN 8
int sendConIno_(char *__ip,int __port, int type);
int port=6789;
int pdt[8];
int main(int argc, char** argv) {
	twc tc;
	readconfig("wd1024.conf",&tc); //read comfig file and setting the envoiment
        memset(&pdt,0,40);
        int sin_len;
	int cli_pro_id;
        unsigned char buffer[MESSAGEIDLEN+OPTIONLEN+MESSAGELEN+3];
        signal(SIGCHLD,&signalHandel);  //reigster the function that deal with defunct process
	signal(SIGINT,&signalHandel);  //reigster the function that deal with defunct process
        int socket_descriptor;
        struct sockaddr_in sin;
        sin_len = inint__cd23(&socket_descriptor,&sin,port);
        if(sin_len <0)
        {
                if(sin_len==-2)
                {
                        print_error(__PORT_HAS_BEEN_USE__);
                }
	        exit(-1);
        }
        printf("Waiting for data form server \n");
        
        sendConIno_("",0,0);
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
                                        if( waitpid(pdt[i], &childStatus, WNOHANG)==pdt[i])
                                          {
                                                  printf("process:%d has been collection\n",pdt[i]);
                                                  pdt[i]=0;
                                          }
                                  }
                        }
	}
	else if(signo==2)
	{
                sendConIno_("",0,1);
		exit(1);
	}
    	return;

}
int sendConIno_(char *__ip,int __port, int type)
{
        msg *inmsg = (msg *)malloc(sizeof(msg));
        if(inmsg==NULL)
        {
                return 2000;
        }
        switch(type)
        {
                case 0:
                {
                        writeAlive(inmsg,0);
                        break;
                }
                case 1:
                {

                        writeDetch(inmsg,0);
                        break;
                }

        }
        int sendval = isend("127.0.0.1",1024,inmsg);
        if(sendval!=0)
        {
               return sendval; 
        }
        free(inmsg);
        return 0;
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
		if(isend("127.0.0.1",1024,&message)!=0)
		{
			print_sw(DEBUG,PUTERR,"\nerror\n");
		}
	}
	return 0;

}
