#include "readconfig.h"
int readconfig(char * path, twc* config)
{

	FILE * fp;
	unsigned char buffer[BUFFERREDLEN] = { 0 };
        unsigned char param[20] = { 0 };
     	fp = fopen(path, "r");
     	if (fp == NULL)
	{
		return 2;
	}
        char *p = NULL;
        int serverl = 0;
    	while (fgets((char *)buffer, BUFFERREDLEN, fp) != NULL) {
                trim((char *)buffer);
		if((buffer[0]=='#')||(buffer[0]==';'))
		{
		}
		else
		{
                        
			if(strstr((const char *)buffer,LPORT)!=NULL)
			{
			        strncpy((char *)param,(const char *)buffer+strlen(LPORT),strlen((const char *)buffer)-strlen(LPORT));	
                                config->lport = atoi((const char *)param);
			}
			else if(strstr((const char *)buffer,SPORT)!=NULL)
			{
			        strncpy((char *)param,(const char *)buffer+strlen(SPORT),strlen((const char *)buffer)-strlen(SPORT));	
                                config->sport = atoi((const char *)param);
                        }
			else if(strstr((const char *)buffer,CLIID)!=NULL)
			{
			        strncpy((char *)param,(const char *)buffer+strlen(CLIID),strlen((const char *)buffer)-strlen(CLIID));	
                                config->client_id = (unsigned int)atoi((const char *)param);
                        }
			else if(strstr((const char *)buffer,SERVER)!=NULL)
			{
			        strncpy((char *)param,(const char *)buffer+strlen(SERVER),strlen((const char *)buffer)-strlen(SERVER));	
                                memcpy(config->server_v4[serverl],param,16);
                                //there have a buffer ,config->server_v4 could out of bound
                                serverl ++;
                        }
                        else{
                        }
		}
                
       		memset(param,0,BUFFERREDLEN); 
       		memset(buffer,0,BUFFERREDLEN); 
     	}

     return 0;
}
