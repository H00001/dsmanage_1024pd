#include "message.h"
void inint(msg * obj)
{
	memset(obj,0,sizeof(msg));

}
void writeMessage(msg * obj,char * _message_3c21)
{
    clearMessage(obj);
	if(strlen(_message_3c21) > MESSAGELEN -1)
    {
        obj->code = 48;
	printf("sigment error");
    }
    else{
	printf("sigment not error");
    	for(int i = 0;_message_3c21[i]!=0;i++)
	    {
	    	obj->message[i] = _message_3c21[i];
	    }
    }
}
void clearMessage(msg * obj)
{
    memset(&(obj->message),0,MESSAGELEN);
}
