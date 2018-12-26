#include "../sharelib/output.h"
#include "../sharelib/oncesend.h"
#define IPPORT_V4 6789
#define CLILEN_V4 3
void waittingforreceive(int socket_descriptor,struct sockaddr_in * sin);
int inint__cd23(struct sockaddr_in *sin,int port);
int isend_m(int socket_descriptor,unsigned const char * ip,int port,msg *message );
void message_handle_input(int s_direscpt,int *cpid,unsigned short *mids);
