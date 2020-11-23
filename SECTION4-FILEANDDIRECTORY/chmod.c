#include<sys/stat.h>
#include<stdio.h>
int main(void){
	struct stat buf;
	if(stat("foo",&buf)<0)
		printf("stat error\n");
	if(chmod("foo",buf.st_mode & ~S_IXGRP | S_ISGID)<0)
		printf("chmod error\n");
	return 0;
}
