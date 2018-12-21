#include "message.h"
void inint(msg * obj)
{
	memset(obj,0,sizeof(msg));
}
int writeMessage(msg * obj,unsigned const char * _message_3c21)
{
        clearMessage(obj);
    	for(int i = 0;i<MESSAGELEN-1;i++)
	{
	        obj->message[i] = _message_3c21[i];
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
                obj->message[i] = (val&movecode)>>((long_len-i)*8);
                movecode = movecode << 8;
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

int changeTomsg(unsigned char * buffer,msg * obj){
        obj->clientid = buffer[0];
        obj->messageid[0] = buffer[1];
        obj->messageid[1] = buffer[2];
        obj->code = buffer[CLIENTIDLEN+MESSAGEIDLEN];
        for(int i = 0;i<OPTIONLEN;i++){
                obj->option[i] = buffer[CLIENTIDLEN+MESSAGEIDLEN+CODELEN+i];
        }
        for(int i = 0;i<MESSAGELEN;i++){
                obj->message[i] = buffer[CLIENTIDLEN+MESSAGEIDLEN+CODELEN+OPTIONLEN+i];
        }
        return 0;
}

