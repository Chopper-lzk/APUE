#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
int main(){
    umask(0);
    if(creat("foo",RWRWRW)<0)
	    printf("file creat error\n");
    umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if(creat("bar",RWRWRW)<0)
	    printf("file creat error\n");
    return 0;
}
	    

