#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
    if(argc!=2){
	    printf("error, usage: ./a.out <descriptor#>\n");
            return 0;
    }
    int fd=atoi(argv[1]);
    int var;
    if((var=fcntl(fd,F_GETFL,0))==-1){
	    printf("fcntl error for fd %d\n",fd);
            return 0;
    }
    switch(var& O_ACCMODE){
	    case O_RDONLY:
		    printf("read only,");
		    break;
	    case O_WRONLY:
		    printf("write only,");
		    break;
	    case O_RDWR:
		    printf("read write,");
		    break;
	    default:
		    printf("unknown access mode,");
    }
    if(var & O_APPEND)
	    printf("append |");
    if(var & O_NONBLOCK)
	    printf("nonblocking |");
#if defined(O_SYNC)
    if(var & O_SYNC)
	    printf("synchronous writes |");
#endif
#if defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
    if(var & O_FSYNC)
	    printf("synchronous writes |");
#endif 
    putchar('\n');
    return 0;
}

