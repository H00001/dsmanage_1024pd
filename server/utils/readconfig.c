#include "readconfig.h"
#define BUFFERREDLEN 20
int readconfig(char * path, twc* config)
{

	FILE * fp;
	unsigned char buffer[BUFFERREDLEN] = { 0 };
     	fp = fopen(path, "r");
     	if (fp == NULL)
	{
		return 30;
	}
    	while (fgets(buffer, BUFFERREDLEN, fp) != NULL) {
         	printf("%s", buffer);
		if((buffer[0]=='#')||(buffer[0]==';'))
		{
		}
		else
		{
			if(strstr(buffer,"port"))
			{
				
			}
		}
       		memset(buffer,0,BUFFERREDLEN); 
     	}

     return 0;
}
