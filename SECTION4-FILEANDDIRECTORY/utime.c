#include<utime.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc,char* argv[]){
	struct utimbuf time;
	struct stat statbuf;
	int i,fd;
	for(i=1;i<argc;i++){
		if(stat(argv[i],&statbuf)<0){
			printf("stat error\n");
			continue;
		}
		if((fd=open(argv[i],O_RDWR|O_TRUNC))<0){
			printf("open error\n");
			continue;
		}
		close(fd);
		time.actime=statbuf.st_atime;
		time.modtime=statbuf.st_mtime;
		if(utime(argv[i],&time)<0){
			printf("utime error\n");
			continue;
		}
	}
	return 0;
}

