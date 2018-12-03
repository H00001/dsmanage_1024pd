#include "message.h"
void inint(msg * obj)
{
	memset(obj,0,sizeof(msg));

}
int writeMessage(msg * obj,char * _message_3c21)
{
        clearMessage(obj);
        if(strlen(_message_3c21) > MESSAGELEN -1)
        {
                obj->code = 48;
                return -1;
        }
        else{
    	        for(int i = 0;_message_3c21[i]!=0;i++)
	        {
	    	        obj->message[i] = _message_3c21[i];
                }
        }
        return 0;
}
void clearMessage(msg * obj)
{
    memset(&(obj->message),0,MESSAGELEN);
}
