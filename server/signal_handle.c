#include "stdafx.h"
extern int pdt[PDTLEN];
extern int socket_descriptor;
extern twc tc;
void signalHandel(int signo) 
{
         //the main use is deal with the defunct process
         if(signo==SIGCHLD){
                  int childStatus;
                 for(int i = 0;i<PDTLEN;i++){
                        if(pdt[i]!=0)
                        {
                                 if(waitpid(pdt[i], &childStatus, WNOHANG)==pdt[i])
                                 {
                                          pdt[i]=0;
                                 }
                        }
                 }
         }
         else if(signo==SIGINT)
         {
                 sendConIno_(socket_descriptor,tc.server_v4[0],tc.sport,1,tc.client_id);
                 exit(1);
         }
         else if(signo==SIGHUP)
        {
         }
        return;

}
