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
void __inline_long_put_bytes(msg *obj,long val)
{
        //this obj is safe,because it only can be called inline function ;  
         long movecode = 0x00000000000000ffL;
         int long_len = sizeof(long) - 1;
         for(int i=long_len;i>=0;i--)
         {
                movecode = movecode << ((long_len-i)*8);
                obj->message[i] = (val&movecode)>>((long_len-i)*8);
         }

}
int writeAlive(msg *obj,int cliid)
{
        if(obj==NULL)
        {
                return __NULL_POINT_ERROR__;
        }
        else
        {
                inint(obj);
                __inline_long_put_bytes(obj, time(NULL));
                obj->clientid = cliid;
                obj->messageid[0] = 0;
                obj->messageid[0] = 0;
                obj->code = 0x00;
        }
        
        return 0;
}
int writeDetch(msg *obj,int cliid)
{
        if(obj==NULL)
        {
                return __NULL_POINT_ERROR__;
        }
        else
        {
                inint(obj);
                __inline_long_put_bytes(obj, time(NULL));
                obj->clientid = cliid;
                obj->messageid[0] = 0;
                obj->messageid[0] = 0;
                obj->code = 0x90;
        }
        return 0;
}  

