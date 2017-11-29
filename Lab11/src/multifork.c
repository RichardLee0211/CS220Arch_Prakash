#include<stdio.h>
#include<unistd.h>

int main(){
    fork();
    printf("line1\n");
    printf("pid: %d ppid: %d\n", getpid(), getppid());
    fork();
    printf("line2\n");
    printf("pid: %d ppid: %d\n", getpid(), getppid());
    if(fork() == 0){
        printf("line3\n");
        printf("pid: %d ppid: %d\n", getpid(), getppid());
    }
    else{
        printf("Line4\n");
        printf("pid: %d ppid: %d\n", getpid(), getppid());
    }
    return 0;
}
