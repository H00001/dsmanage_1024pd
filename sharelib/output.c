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

void print_error(int errorcode)
{
        char * errors = NULL;
        if(errorcode<2000)
        {
                errors = strerror(errorcode);
        }
        else{
                switch(errorcode)
                {
                        case __PORT_HAS_BEEN_USE__:
                        errors = __PORT_HAS_BEEN_USE_S;
                        break;

                }
        }
        print_sw(1,PUTERR,errors);
        print_sw(1,PUTERR,"\n");
}
void print_first()
{
        system("clear");
        int filed;
        int len;
        filed = open("../sharelib/content/writefirst",O_RDONLY);
        char fbuffer[FILEBUFFER];
        if(filed > 0)
        {
                memset(fbuffer,0,FILEBUFFER);
                
                while((len = read(filed,fbuffer,FILEBUFFER-1))!=0){
                        for(int i = 0;i<len;i++)
                        {
                                printf("%c",fbuffer[i]);

                                fflush(stdout); //you must flush the buffer stdout
                                usleep(100000);

                        }
                }
                        
               
        }
        else
        {
                printf("error");
        }
}
