#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "utils/runcmd.h"
#include "../sharelib/oncesend.h"
#include "utils/udpsocket.h"
#include "utils/readconfig.h"
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define CLIENTID 1
#define PDTLEN 8
int sendConIno_(unsigned char *__ip,int __port, int type,int client_id_12bf);
void writeValWithStatus(msg* __msg__, int status);
int message_deal_Hander(unsigned char * buffer);
void signalHandel(int signo);

