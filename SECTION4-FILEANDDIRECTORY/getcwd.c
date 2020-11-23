#include<unistd.h>
#include<stdio.h>
#define MAX_LINE_LEN 100

int main(){
	char buf[MAX_LINE_LEN];
	if(chdir("..")<0)
		printf("chdir error\n");
        if(getcwd(buf,MAX_LINE_LEN)==NULL)
		printf("getcwd error\n");
	printf("cwd = %s\n",buf);
	return 0;
}

