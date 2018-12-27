#define __SHARE_OUTPUT__
#define DEBUG 0
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "myerror.h"
#define FILEBUFFER 1024
typedef enum puttypes
{
        NOPUT=0,PUTERR,PUTSTD

}puttype;
void print_sw(int isput,puttype __sw,char * __message);

void print_error(int errorcode);

void print_first();
