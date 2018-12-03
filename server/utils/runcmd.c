#include "runcmd.h"
int  cmd_system__0a40(const char* command,char *__result__,int bufferlen)
{
    int flag = 0;
    FILE *fpRead =  popen(command, "r");
    if(!fpRead)
    {
	    return errno;
    }
    memset(__result__,0,bufferlen);
    while(fgets(__result__+flag,bufferlen-1,fpRead)!=NULL)
    {
        for(int i =0; __result__[i]!=0;i++)
        {
                flag = i+1;
        }
        __result__[flag-1] = ' ';
    }
    pclose(fpRead);
    return 0;
}

