#include<unistd.h>
#include<stdio.h>
int main(void){
	int pos;
	if((pos=lseek(STDIN_FILENO, 0, SEEK_CUR)==-1))
		printf("error seek\n");
	else
	        printf("seek ok: %d\n",pos);
	return 0;
}

	 

