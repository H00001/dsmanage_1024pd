#define __MESSAGE_H__
#define MESSAGEIDLEN 2
#define OPTIONLEN 4
#define MESSAGELEN 1000
#define REQUEST 0x01
#define RESPONSE 0x00
#define SHELL 0x02
#define ISALIVE 0x04
#define FAIL 0x10
#define BOF 0x20
#define CMDERROR 0x40
#define SUCCEED 0x00
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "myerror.h"
typedef unsigned char byte;
typedef struct __message__
{
        byte clientid;
        byte messageid[MESSAGEIDLEN];
        byte code;
        byte option[OPTIONLEN];
        byte message[MESSAGELEN];

}msg;

int writeMessage(msg * obj,unsigned const char * _message_3c21);
void clearMessage(msg * obj);
void inint(msg* obj);
int writeAlive(msg *obj,int cliid);
int writeDetch(msg *obj,int cliid);
void __inline_long_put_bytes(msg *obj,long val);
int changeTomsg(unsigned char * buffer,msg * obj);
