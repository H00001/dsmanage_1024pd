#include "utils/runcmd.h"
#include "../sharelib/oncesend.h"
#include "../sharelib/output.h"
#include "utils/udpsocket.h"
#include "utils/readconfig.h"
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#define CLIENTID 1
#define PDTLEN 8
int sendConIno_(unsigned char *__ip,int __port, int type,int client_id_12bf);
void writeValWithStatus(msg* __msg__, int status);
int message_deal_Hander(unsigned char * buffer);
void signalHandel(int signo);

