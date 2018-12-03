#include "change.h"
int changeTomsg(char * buffer,msg * obj){
	obj->clientid = buffer[0];
        obj->messageid[0] = buffer[1];
        obj->messageid[1] = buffer[2];
        obj->code = buffer[3];
	for(int i = 0;i<OPTIONLEN;i++){
                obj->option[i] = buffer[3+i];
        }
        for(int i = 0;i<MESSAGELEN;i++){
                obj->message[i] = buffer[8+i];
        }
	return 0;
}
