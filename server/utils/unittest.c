#include "runcmd.h"
int main()
{
	char buffer[1024];
        cmd_system__0a40("top -n 1",buffer,1024);
        return 0;
}
