#include<unistd.h>
#include<stdio.h>
#define BUFFSIZE 100
int main(){
	char buf[BUFFSIZE];
	int n;
	while((n=readlink("./a/t", buf, BUFFSIZE))>0)
		printf("%s",buf);
	if(n==-1)
		printf("read error\n");
	else 
		printf("***read over***\n");
	return 0;
}

