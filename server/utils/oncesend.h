#include "../../sharelib/change.h"
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <errno.h>

#include "../../sharelib/output.h"

int isend(unsigned const char * ip,int port,msg *message );
