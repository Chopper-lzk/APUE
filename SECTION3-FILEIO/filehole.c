#include<fcntl.h>
#include<stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(){
    int fd;
    char buf1[] = "abcdefg";
    char buf2[] = "ABCDEFG";
    if((fd=creat("test.txt",FILE_MODE))<0)
	    printf("file creat error\n");
    if(write(fd,buf1,7)!=7)
	    printf("file write error\n");
    if(lseek(fd,1024,SEEK_SET)==-1)
	    printf("seek error\n");
    if(write(fd,buf2,7)!=7)
	    printf("write error\n");
    return 0;
}
