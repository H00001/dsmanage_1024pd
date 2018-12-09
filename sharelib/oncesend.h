#include <string.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
//#include <time.h>
#include <errno.h>
#include "message.h"
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int isend(unsigned const char * ip,int port,msg *message);
