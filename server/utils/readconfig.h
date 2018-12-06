#ifndef __auto_config_
#define __auto_config_
#else
#define __not_auto_config
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum outputflag
{
        NOOUTPUT = 0

}op;

typedef struct  twd1024_config
{
        unsigned int _output_flag;
	int port;
        unsigned char client_id;

}twc;

int readconfig(char * path, twc* config);
