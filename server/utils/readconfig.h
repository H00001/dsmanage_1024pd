#ifndef __auto_config_
#define __auto_config_
#else
#define __not_auto_config
#endif
typedef enum outputflag
{
        NOOUTPUT = 0

}op;

typedef struct  twd1024_config
{
        unsigned int _output_flag;
        unsigned char client_id;

}twc;

int readconfig(char * path, twc* config);
