#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
# define MAXLINE 50

void sig_int(int);

int main(){
    char buf[MAXLINE];
    pid_t pid;
    int status;
    
    if(signal(SIGINT, sig_int)==SIG_ERR)   //注册信号处理函数 SIGINT --> sig_int()
	    printf("signal error\n");

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

//sig_int() 函数
void sig_int(int signo){
	printf("interrupt\n");
}



