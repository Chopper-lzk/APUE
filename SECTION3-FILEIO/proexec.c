#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
# define MAXLINE 50
int main(){
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while(fgets(buf,MAXLINE,stdin)!=NULL){
	    if(buf[strlen(buf)-1]=='\n')
		    buf[strlen(buf)-1]=0;
	    if((pid=fork())<0){
		    printf("sub process creation failed\n");
		    continue;
	    }

	    //child process
	    if(pid==0){
		    if(execlp(buf,buf,NULL)<0)
		    printf("program %s exec falied\n",buf);
		    exit(127);
	    }

	    //parent process
	    if(waitpid(pid,&status,0)<0)
		    printf("waitpid error\n");
	    printf("%% ");
    }
    exit(0);
}


