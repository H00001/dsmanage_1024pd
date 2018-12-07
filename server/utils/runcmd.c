#include "runcmd.h"
int  cmd_system__0a40(const char* command,unsigned char *__result__,int bufferlen)
{
        int flag = 0;
        FILE *fpRead =  popen(command, "r");
        if(!fpRead)
        {
	       return errno;
        }
        memset(__result__,0,bufferlen);
        
        if((flag=fread(__result__,1,bufferlen-1,fpRead))==bufferlen-1)
        {
                return 40;
        }
        if(flag!=0)
        {
        }
        if(pclose(fpRead)!=0)
        {
                printf("\nclose error\n::%d",errno);
                return -3217;
        }
        return 0;
        
}

