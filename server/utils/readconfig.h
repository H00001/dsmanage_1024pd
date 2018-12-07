#ifndef __auto_config__
#define __auto_config__
#else
#define __not_auto_config__
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../../sharelib/str_help.h"
#define CLIID "clientid="
#define SPORT "sport="
#define LPORT "lport="
#define SERVER "server="
#define SERVERLEN 5
#define BUFFERREDLEN 20
typedef enum outputflag
{
        NOOUTPUT = 0

}op;

typedef struct  twd1024_config
{
        unsigned char server_v4[SERVERLEN][16];
        //unsigned char server_v6[SERVERLEN][128];
        unsigned int _output_flag;
        unsigned int sport;
        unsigned int lport;
        unsigned char client_id;

}twc;

int readconfig(char * path, twc* config);
