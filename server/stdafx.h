#include "utils/runcmd.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include "../sharelib/oncesend.h"
#include "../sharelib/output.h"
//#include "utils/udpsocket.h"
#include "utils/readconfig.h"
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#define CLIENTID 1
#define PDTLEN 8
#define STD_MSG 4000
#define MBUFSIZ 30
#define CONTFILE "wd1024.conf"
void writeValWithStatus(msg* __msg__, int status);
void signalHandel(int signo);
int message_deal_Hander(int sockdscp,unsigned char * buffer,char *pathm,struct in_addr aip,short int port);
int sendConIno_(int desc, unsigned char *__ip,int __port, int type,int client_id_12bf);
