#include<unistd.h>
#include<stdio.h>
#define BUFFSIZE 5

int main(int argc, char* argv[]){
    int n;
    char buff[BUFFSIZE];
    while((n=read(STDIN_FILENO,buff,BUFFSIZE))>0){
	    if(write(STDOUT_FILENO,buff,n)!=n)
		    printf("write error\n");
    }
    if(n<0)
	    printf("read error");
    return 0;
}


