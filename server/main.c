#include "stdafx.h"
int port=6789;
int main(int argc, char** argv) {
	twc tc;
	readconfig("wd1024.conf",&tc);
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
	        exit(-1);
        }
        printf("Waiting for data form server \n");
	msg inmsg;
        writeAlive(&inmsg,0);
        isend("127.0.0.1",1024,&inmsg);

        while(1)
        {
                recvfrom(socket_descriptor,&buffer,sizeof(buffer),0,(struct sockaddr *)&sin,&sin_len);
		if(0==(cli_pro_id=fork())){
			message_deal_Hander(buffer);
			return 0;
		}
		else
		{
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
     		pid_t pid;
    		int stat;
    		pid = wait(&stat);    
	}
	else if(signo==2)
	{
		msg exitmsg;
                writeDetch(&exitmsg,0);
		isend("127.0.0.1",1024,&exitmsg);
		exit(1);
	}
    	return;

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
