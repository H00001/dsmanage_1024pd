#include "runcmd.h"
int cmd_system__0a40(unsigned  char* command,unsigned char **__result__,const char * path)
{
        chdir(path); 
        int flag = 0;
	*__result__ = malloc(ONCEREADBUFFERLEN);
        memset(*__result__,0,ONCEREADBUFFERLEN);
        if(*__result__ == NULL)
        {
                //deal malloc fail exception
        }
        FILE *fpRead =  popen((const char *)command, "r");
        if(!fpRead)
        {
	       return errno;
        }
        unsigned char * newblock = NULL;
        while(fread((*__result__)+flag,1,ONCEREADBUFFERLEN,fpRead)==ONCEREADBUFFERLEN)
        {
                flag += ONCEREADBUFFERLEN;
                newblock = calloc(flag+ONCEREADBUFFERLEN,1);
                memcpy(newblock,*__result__,flag);
                *__result__ = newblock;
        }
        if(flag!=0)
        {
        }
        if(pclose(fpRead)!=0)
        {
                return -3217;
        }
        return 0;
        
}

