#include<unistd.h>
#include<stdio.h>

int main(){
	printf("user id: %d\n",getuid());
	printf("group id: %d\n", getgid());
	return 0;
}

