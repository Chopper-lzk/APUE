#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#define buffsize 4096
int main(){
	int n;
	char buff[buffsize];
	while((n=read(STDIN_FILENO,buff,buffsize))>0){
		if(write(STDOUT_FILENO,buff,n)!=n)
			printf("write error\n");
	}
	if(n<0)
		printf("read error\n");
	return 0;
}
