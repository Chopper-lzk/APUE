#include<stdio.h>

void pr_stdio(const char*,FILE*);
int main(void){
	FILE* fp;
	fputs("enter any one character\n",stdout);
	if(getchar()==EOF)
	printf("getchar error\n");
        pr_stdio("stdin", stdin);
	pr_stdio("stdout", stdout);
	pr_stdio("stderr", stderr);
	if((fp=fopen("./note.txt","r"))==NULL)
		printf("fopen error\n");
	if(getc(fp)==EOF)
		printf("getc error\n");
	pr_stdio("./note.txt", fp);
	return 0;
}
void pr_stdio(const char* name, FILE* fp){
	printf("stream = %s, ", name);
	printf(", buffer size = %ld\n", fp->_IO_buf_end - fp->_IO_buf_base);
}
