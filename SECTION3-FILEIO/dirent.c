#include<stdio.h>
#include<dirent.h>

int main(int argc, char* argv[]){
	DIR    *dp;
	struct dirent  *dirp;
	if(argc!=2){
		printf("error: not a directory\n"); //not a directory
	        return 0;
	}
	dp=opendir(argv[1]);
        if(dp==NULL){
		printf("error: can't open file: %s\n",argv[1]);  //open file argv[1] error
		return 0;
	}
	while((dirp=readdir(dp))!=NULL)
		printf("%s\n",dirp->d_name);
	return 0;
}
	
