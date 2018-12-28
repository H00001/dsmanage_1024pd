#include<string.h>
#define ENABLE 0x00000001
#define DISABLE 0x00000000
typedef struct chain_filter
{
        int (* chin)(char *);
        int enable;
}filter;
int inintChain();
int doChain(char *val);
void setFilter(filter * filterlist,int i,int _enable,int (*func) (char *));
int all_del_chain(char *val);
int ls_chain(char * val);
