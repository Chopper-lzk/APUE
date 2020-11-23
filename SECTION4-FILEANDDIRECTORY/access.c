#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include "apue.h"
int main(int argc,char* argv[]){
	if(argc!=2){
		printf("error, usage: ./a.out <pathname>\n");
		return 0;
	}
	if(access(argv[1],R_OK)<0){
		err_sys("access error");
		return 0;
	}
	if(open(argv[1],O_RDONLY)<0){
		err_sys("open error");
		return 0;
	}
	else
		printf("open ok\n");
	return 0;
}
		
