#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

int main(){
    char* prog = "./runner";

    char** args;
    if(fork() == 0){
        printf("child pid = %d, parent pid = %d\n", getpid(), getppid());
        execvp(prog, args);
        fprintf(stderr, "exec: %s\n", strerror(errno));
        printf("child pid = %d, parent pid = %d\n", getpid(), getppid());
    } else{
        wait(NULL);
    }
    return 0;
}
