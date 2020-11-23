#include<errno.h>
#include<string.h>
#include<stdio.h>
int main(int argc, char* argv[]){
    fprintf(stderr,"EACCESS: %s\n",strerror(EACCES));
    errno=ENOENT;
    perror(argv[0]);
    return 0;
}
