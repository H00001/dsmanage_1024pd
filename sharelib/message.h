#define __MESSAGE_H__
#define MESSAGEIDLEN 2
#define OPTIONLEN 4
#define MESSAGELEN 1000
#include<string.h>
#include<stdio.h>
typedef unsigned char byte;
typedef struct __message__
{
        byte clientid;
        byte messageid[MESSAGEIDLEN];
        byte code;
        byte option[OPTIONLEN];
        char message[MESSAGELEN];

}msg;

void writeMessage(msg * obj,char * _message_3c21);
void clearMessage(msg * obj);

void inint(msg* obj);
