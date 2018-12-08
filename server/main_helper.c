#include "stdafx.h"
void writeValWithStatus(msg* __msg__, int status)
{
        if(status==0)
        {
                __msg__->code = 0x02;
        }
        else if(status == -3217)
        {
                 __msg__->code = 0x12;
        }
        else if(status == 40)
        {
               __msg__->code = 0x32;
        }

}

int sendConIno_(unsigned char *__ip,int __port, int type,int client_id_12bf)
{
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
        int sendval = isend(__ip,__port,inmsg);
        if(sendval!=0)
        {
               return sendval;
        }
        free(inmsg);
        return 0;
}

