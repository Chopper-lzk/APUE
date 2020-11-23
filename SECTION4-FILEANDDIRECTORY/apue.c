#include<errno.h>
#include<string.h>
#include<stdio.h>
void err_sys(const char* ptr){
    fprintf(stdout,"%s: %s\n",ptr,strerror(errno));
}
