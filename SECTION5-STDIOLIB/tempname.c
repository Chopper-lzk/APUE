#include<stdio.h>

int main(int argc, char* argv[]){
	if(argc!=3)
		printf("error, usage: ./a.out <directory> <prefix>\n");
	printf("%s\n", tempnam(argv[1][0]!= ' '?argv[1]:NULL,argv[2][0]!=' '?argv[2]:NULL));
	return 0;
}
