#define __SHARE_OUTPUT__
#define DEBUG 0
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>

typedef enum puttypes
{
        NOPUT=0,PUTERR,PUTSTD

}puttype;
void print_sw(int isput,puttype __sw,char * __message);

