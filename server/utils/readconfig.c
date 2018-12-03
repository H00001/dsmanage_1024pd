#include "readconfig.h"
int readconfig(char * path, twc* config)
{
        int fileid;
        int readlen;

        char  buffer[1025];
        fileid = open(path,O_RDONLY);
        if(fileid < 0)
        {
                return -1;
        }
        else
        {
                read(fileid, buffer, 1024);
                        
        }

}
