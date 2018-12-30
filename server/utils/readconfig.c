#include "readconfig.h"
int readconfig(char * path, twc* config)
{
        memset(config,0,sizeof(twc));
	FILE * fp;
	unsigned char buffer[BUFFERREDLEN] = { 0 };
     	fp = fopen(path, "r");
     	if (fp == NULL)
	{
		return 2;
	}
        int serverl = 0;
    	while (fgets((char *)buffer, BUFFERREDLEN, fp) != NULL) {
                trim((char *)buffer);
		if((buffer[0]=='#')||(buffer[0]==';'))
		{
		}
		else
		{
                        
			if(!startwith((const char *)buffer ,LPORT))
			{
                                config->lport = atoi((const char *)(buffer+strlen(LPORT)));
			}

			else if(!startwith((const char *)buffer,SPORT))
			{
                                config->sport = atoi((const char *)(buffer+strlen(SPORT)));
                        }
			else if(!startwith((const char *)buffer,CLIID))
			{
                                config->client_id = (unsigned int)atoi((const char *)(buffer+strlen(CLIID)));
                        }
		        else if(!startwith((const char *)buffer,SERVER))
			{
                                memcpy(config->server_v4[serverl],buffer+strlen(SERVER),15);
                                serverl ++;
                        }
                
                        else{
                        }
		}
                
       		memset(buffer,0,BUFFERREDLEN); 
     	}

     return 0;
}
