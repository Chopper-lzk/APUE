#include "apue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#define MAX_PATH_LEN 1024

typedef int Myfunc(const char*,const struct stat*,int);
Myfunc myfunc;
char* path_alloc(int*);
int myftw(const char*,Myfunc*);
int dopath(Myfunc*);
long nreg,ndir,nblk,nchr,nfifo,nslink,nsock,ntot;

int main(int argc,char* argv[]){
	int ret;
	if(argc!=2){
		printf("error, usage: ftw <pathname>");
		return -1;
	}
	ret=myftw(argv[1],myfunc);
	if(ret==-1){
		printf("traversal error for %s\n",argv[1]);
		return -1;
	}
	ntot=nreg+ndir+nblk+nchr+nfifo+nslink+nsock;
	if(ntot==0)
		return -1;
	printf("regular files = %7ld, %5.2f %%\n", nreg, nreg*100.0/ntot);
	printf("directory files = %7ld, %5.2f %%\n", ndir,ndir*100.0/ntot);
	printf("block special = %7ld, %5.2f %%\n", nblk,nblk*100.0/ntot);
	printf("char special = %7ld, %5.2f %%\n", nchr, nchr*100.0/ntot);
	printf("fifos = %7ld, %5.2f %%\n", nfifo, nfifo*100.0/ntot);
	printf("socks = %7ld, %5.2f %%\n", nsock, nsock*100.0/ntot);
	printf("symbolic link = %7ld, %5.2f %%\n", nslink, nslink*100.0/ntot);
	return ret;
}		
char* path_alloc(int* size)
{
    char *p = NULL;
    if(!size) return NULL;
    p = malloc(MAX_PATH_LEN);
    if(p)
    *size = MAX_PATH_LEN;
    else
    *size = 0;
    return p;
}
#define FTW_F 1
#define FTW_D 2
#define FTW_DNR 3
#define FTW_NS 4
static char* fullpath;
int myftw(const char* pathname,Myfunc* myfunc){
    int len;
    fullpath=path_alloc(&len);  //alloc for fullpath
    strncpy(fullpath,pathname,len);
    fullpath[len-1]=0;
    return (dopath(myfunc));
}

int dopath(Myfunc* myfunc){
	struct stat statbuf;
	struct dirent *dirp;
	DIR *dp;
        int ret;
	char* ptr;
	if(lstat(fullpath,&statbuf)<0){ //stat error
             return (myfunc(fullpath,&statbuf,FTW_NS));
	}
        if(S_ISDIR(statbuf.st_mode)==0){ //not a directory
	     return (myfunc(fullpath,&statbuf,FTW_F));
        }
	if((ret=myfunc(fullpath,&statbuf,FTW_D))!=0){
	     return ret;
	 }
	ptr=fullpath+strlen(fullpath);
	printf("before: %s\n",fullpath);
	if(ptr[-1]!='/'){
	   *(ptr++)='/';
           *ptr=0;
	}
	printf("after: %s\n",fullpath);
	if((dp=opendir(fullpath))==NULL)
	     return myfunc(fullpath,&statbuf,FTW_DNR);
	while((dirp=readdir(dp))!=NULL){
              if(strcmp(dirp->d_name,".")==0||strcmp(dirp->d_name,"..")==0)
	           continue;
	      strcpy(ptr,dirp->d_name);
	      if((ret=dopath(myfunc))!=0)
	          break;
        }
        ptr[-1]=0;
	if(closedir(dp)<0){
	   err_sys("can't close directory");
	   return -1;
	}
	return (ret);
}

int myfunc(const char* pathname, const struct stat* statbuf,int type){
	switch(type){
		case FTW_F:
			switch(statbuf->st_mode & S_IFMT){
				case S_IFREG: nreg++;
					      break;
				case S_IFBLK: nblk++;
					      break;
				case S_IFCHR: nchr++;
					      break;
			        case S_IFIFO: nfifo++;
					      break;
			        case S_IFLNK: nslink++;
					      break;
			        case S_IFSOCK: nsock++;
					       break;
			        case S_IFDIR:
					       printf("err S_IFDIR for %s\n",pathname);
					       return -1;
			}
			break;
	       case FTW_D:
			ndir++;
			break;
	       case FTW_DNR:
			printf("can't read directory: %s\n", pathname);
			return -1;
	       case FTW_NS:
			printf("stat error: %s\n",pathname);
			return -1;
	       default:
			printf("unknown error");
			return -1;
        }
	return 0;
}



