#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
	if(open("a.txt",O_RDWR)<0)
		printf("open error\n"); if(unlink("a.txt")<0)
		printf("unlink error\n");
	printf("unlinked\n");
	sleep(15);
	printf("done\n");
	return 0;
}


