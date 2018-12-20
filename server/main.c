#include "stdafx.h"
static twc tc;
key_t uniquekey = 10000;
static  int msgid;
int pdt[PDTLEN]; 
int __main__init()
{
        memset(&tc,0,sizeof(tc));
        memset(&pdt,0,sizeof(int)*PDTLEN); //inint pdt
        signal(SIGCHLD,&signalHandel);  //reigster the function that deal with defunct process
        signal(SIGHUP,&signalHandel);  //reigster the function that deal with defunct process
	signal(SIGINT,&signalHandel);  //reigster the function that deal with ctrl_c request
        if((msgid = msgget(uniquekey, IPC_CREAT |  0666)) == -1) {
	        print_error(errno);
	        exit(errno);
        }                
        return  readconfig(CONTFILE,&tc);
}

typedef struct _msg_struc_
{
        long msgtype;
        char text[MBUFSIZ];
} sigmsg;

int main() {
        int erro = __main__init();
        unsigned int sin_len;
	int cli_pro_id;
        int socket_descriptor;
        struct sockaddr_in sin;
        char pathm[MBUFSIZ];
        getcwd(pathm,MBUFSIZ);
        if(erro!=0)
        {
                print_error(erro);
                exit(-1);
        }
        unsigned char buffer[MESSAGEIDLEN+OPTIONLEN+MESSAGELEN+3];
        sin_len = inint__cd23(&socket_descriptor,&sin,tc.lport);
        if(sin_len==-2)
        {
                print_error(__PORT_HAS_BEEN_USE__);
	        return -2;
        }
        if(sin_len==-1)
        {
                print_error(__PORT_HAS_BEEN_USE__);
	        return -2;
        }
        else
        {
                printf("[INFO] waiting for data form server \n");
        }
        
        sendConIno_(tc.server_v4[0],tc.sport,0,tc.client_id);
        while(1)
        {
                recvfrom(socket_descriptor,&buffer,sizeof(buffer),0,(struct sockaddr *)&sin,&sin_len);
		if(0==(cli_pro_id=fork())){
			message_deal_Hander(buffer,pathm);
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

                        sigmsg recvdate;
                        if(msgrcv(msgid, (void  *)&recvdate, MBUFSIZ, STD_MSG, IPC_NOWAIT) == -1) {
	                   //     print_error(errno);
                        }

                        else{
                            strcpy(pathm,recvdate.text);
                        }
			//printf("\nprocess:%d deal the message\n",cli_pro_id);
		}
    	}
        close(socket_descriptor);
        exit(0);
        return (EXIT_SUCCESS);
}

void signalHandel(int signo) {
	//the main use is deal with the defunct process
	if(signo==SIGCHLD){
                int childStatus;
                for(int i = 0;i<PDTLEN;i++){
                       if(pdt[i]!=0)
                       {
                                if(waitpid(pdt[i], &childStatus, WNOHANG)==pdt[i])
                                {
                                         pdt[i]=0;
                                }
                        }
                }
	}
	else if(signo==SIGINT)
	{
                sendConIno_(tc.server_v4[0],tc.sport,1,tc.client_id);
		exit(1);
	}
	else if(signo==SIGHUP)
	{
        }
    	return;

}
int message_deal_Hander(unsigned char * buffer,char *pathm)
{
	msg message;
        char type_std[10] = {0};
        unsigned char resultbuffer[MESSAGELEN];
        inint(&message);
	changeTomsg(buffer,&message);
        if(message.clientid!=tc.client_id)
        {
                return 0;
        }
        else if(strlen((const char *)message.message) == 1&& message.message[0]=='\n')
        {
                return 0;
        }
        if((message.code&0x01)==1)
        {
        	if(message.code==(REQUEST|SHELL))
        	{
                        if(((*(message.message))=='c')&&((*((message.message+1)))=='d'))
                        {
                                sigmsg send_msg;
                                strcpy(send_msg.text,message.message+3);
                                send_msg.msgtype = STD_MSG;
                                if(msgsnd(msgid, (sigmsg  *)(&send_msg), MBUFSIZ, 0) == -1) {
                                        print_error(errno);
	                                exit(2);
	                        }
                                return 0;
                        }
        		writeValWithStatus(&message, cmd_system__0a40(message.message,resultbuffer,MESSAGELEN,pathm));
                        strcpy(type_std,"shell");
			writeMessage(&message,resultbuffer);
		}
                else if(message.code==(REQUEST|ISALIVE))
                {
                        strcpy(type_std,"alive");
                        sendConIno_(tc.server_v4[0],tc.sport,0,tc.client_id);
                }
		else if((message.code&0x02)==0)
		{

      		}
                else
                {
                }
                printf("message:%d%d\t type:%s\t from:%d\n",message.messageid[0],message.messageid[1],type_std,message.clientid);
                memset(type_std,0,10);
		if(isend(tc.server_v4[0],tc.sport,&message)!=0)
		{
			print_sw(DEBUG,PUTERR,"\nerror\n");
		}
	}
	return 0;

}
