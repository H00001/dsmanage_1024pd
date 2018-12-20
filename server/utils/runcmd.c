#include "runcmd.h"
int cmd_system__0a40(unsigned  char* command,unsigned char *__result__,int bufferlen,const char * path)
{
        chdir(path); 
        int flag = 0;
        /**
        if(((*command)=='c')&&((*(command+1))=='d'))
        {
                int popc = 3;
                while(*(command+popc)!='\n')
                        popc ++;
                *(command+popc) = 0;
                strcpy(pathm,command+3);
        }
       **/
        FILE *fpRead =  popen((const char *)command, "r");
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
                return -3217;
        }
        return 0;
        
}

