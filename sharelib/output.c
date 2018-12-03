#include "output.h"

void print_sw(int isput,puttype __sw,char * __message)
{
    if(isput){
        if(__sw==NOPUT)
        {

        }
        else if(__sw==PUTERR)
        {
                fputs(__message, stderr);
        }
        else if(__sw==PUTSTD)
        {
                fputs(__message, stdout);
        }
    }
    else{
    }
}
