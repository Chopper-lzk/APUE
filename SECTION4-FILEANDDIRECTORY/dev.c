#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
int main(int argc, char* argv[]){
	struct stat statbuf;
	for(int i=1;i<argc;i++){
		if(stat(argv[i],&statbuf)<0){
			printf("stat error\n");
			continue;
		}
		printf("dev= %d/%d\n", major(statbuf.st_dev),minor(statbuf.st_dev));
		if(S_ISCHR(statbuf.st_mode) || S_ISBLK(statbuf.st_mode)){
			printf(" (%s) rdev= %d/%d\n",S_ISCHR(statbuf.st_mode)?"character":"block",major(statbuf.st_rdev),minor(statbuf.st_rdev));
	        }
	}
	return 0;
}


