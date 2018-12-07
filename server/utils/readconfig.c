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
    	while (fgets(buffer, BUFFERREDLEN, fp) != NULL) {
                trim(buffer);
		if((buffer[0]=='#')||(buffer[0]==';'))
		{
		}
		else
		{
                        
			if(strstr(buffer,LPORT)!=NULL)
			{
			        strncpy(param,buffer+strlen(LPORT),strlen(buffer)-strlen(LPORT));	
                                config->lport = atoi(param);
			}
			else if(strstr(buffer,SPORT)!=NULL)
			{
			        strncpy(param,buffer+strlen(SPORT),strlen(buffer)-strlen(SPORT));	
                                config->sport = atoi(param);
                        }
			else if(strstr(buffer,CLIID)!=NULL)
			{
			        strncpy(param,buffer+strlen(CLIID),strlen(buffer)-strlen(CLIID));	
                                config->client_id = atoi(param);
                        }
			else if(strstr(buffer,SERVER)!=NULL)
			{
			        strncpy(param,buffer+strlen(SERVER),strlen(buffer)-strlen(SERVER));	
                                memcpy(config->server_v4[serverl],param,16);
                                //there have a buffer ,config->server_v4 could out of bound
                                serverl ++;
                        }
                        else{
                                printf("not east\n");
                        }
		}
                
       		memset(param,0,BUFFERREDLEN); 
       		memset(buffer,0,BUFFERREDLEN); 
     	}

     return 0;
}
