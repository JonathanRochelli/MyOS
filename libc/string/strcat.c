#include "../include/string.h"

char* strcat(char* dest, char* src)
{
    char* tmp = dest;

    while(*dest) dest++;
    while((*dest++ = *src++) != 0);

    return tmp;

}