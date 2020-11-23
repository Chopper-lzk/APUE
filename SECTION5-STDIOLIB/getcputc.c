#include<stdio.h>

int main(void){
	int c;
	while((c=getc(stdin))!=EOF){
		if(putc(c,stdout)==EOF)
			printf("putc error\n");
	}
	if(ferror(stdin))
		printf("gect error");
	return 0;
}

