#include "stdafx.h"
void writeValWithStatus(msg* __msg__, int status)
{
        if(status==0)
        {
                __msg__->code = (SUCCEED|RESPONSE|SHELL);
        }
        else if(status == -3217)
        {
                 __msg__->code = (SHELL|FAIL|CMDERROR|RESPONSE);
        }
        /**
         * else if(status == 40)
        {
               __msg__->code = (SHELL|FAIL|BOF|RESPONSE);
        }
        **/

        else if(status == -1)
        {
        //        printf("ddddd###--%d",errno);
        }
}

int sendConIno_(int desc, unsigned char *__ip,int __port, int type,int client_id_12bf)
{
//        printf("ip:%s:port:%d\n",__ip,__port);
        msg *inmsg = (msg *)malloc(sizeof(msg));
        if(inmsg==NULL)
        {
                return 2000;
        }
        switch(type)
        {
                case 0:
                {
                        writeAlive(inmsg,client_id_12bf);
                        break;
                }
                case 1:
                {

                        writeDetch(inmsg,client_id_12bf);
                        break;
                }

        }
        int sendval = isend_m(desc,__ip,__port,inmsg);
        if(sendval!=0)
        {
               return sendval;
        }
        free(inmsg);
        return 0;
}
int init_std_function(func_map * mapping)
{
	mapping[0].name = "who";
	mapping[0].funx = is_alive; 
}
