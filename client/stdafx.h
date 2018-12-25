#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "../sharelib/output.h"
#include "../sharelib/oncesend.h"

#define IPPORT_V4 6789
#define CLILEN_V4 3
void waittingforreceive();

