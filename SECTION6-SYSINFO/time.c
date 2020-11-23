#include<time.h>
#include<sys/time.h>
#include<stdio.h>
int main(){
        time_t time0;
        struct timeval time1;
        time(&time0);
        gettimeofday(&time1,NULL);
        printf("sec: %ld\n",time0);
        printf("sec: %ld, usec: %ld\n", time1.tv_sec,time1.tv_usec);
        return 0;
}
