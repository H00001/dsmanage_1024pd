#include "first_chain_manage.h"
filter filterlist[10];
int inintChain()
{
        memset(filterlist,0,sizeof(filter)*10);
        setFilter(filterlist,1,DISABLE,&all_del_chain);
        #ifdef _M_P_L_MOD_
        setFilter(filterlist,0,ENABLE,&ls_chain);
        #else

        #endif
        return 0;
}
int doChain(char *val)
{
        inintChain();
        for(int i = 0 ;i<10;i++)
        {
                if(filterlist[i].enable!=0)
                {
                        if(filterlist[i].chin(val)!=0)
                        {
                                return -1;
                        }
                }
        }
        return 0;

}
int ls_chain(char * val)
{
        if(val[0]=='l'&&val[1]=='s')
        {
                strcpy(val+strlen(val)," -l");
        }
        return 0;
}
int all_del_chain(char *val)
{
        memset(val,0,strlen(val));
        return 0;
}
void setFilter(filter * filterlist,int i,int _enable,int (*func) (char *))
{

        filterlist[i].chin=func;
        filterlist[i].enable=_enable;
}
