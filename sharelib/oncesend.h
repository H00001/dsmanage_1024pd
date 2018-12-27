#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include "message.h"
#include <unistd.h>

int isend(unsigned const char * ip,int port,msg *message);
int isend_m(int socket_descriptor,unsigned const char * ip,int port,msg *message);
int inint__cd23(struct sockaddr_in *sin ,int port);
