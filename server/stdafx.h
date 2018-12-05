#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "utils/oncesend.h"
#include "utils/runcmd.h"
#include "utils/udpsocket.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define CLIENTID 1
void writeValWithStatus(msg* __msg__, int status);
int message_deal_Hander(unsigned char * buffer);
void signalHandel(int signo);

