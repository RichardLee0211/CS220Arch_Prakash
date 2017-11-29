#include<stdio.h>
#include<unistd.h>

int main(){
    int x = 1;
    pid_t pid;
    pid = fork();
    if(pid == 0){
        x++;
        printf("In child\n");
        printf("pid of child: %d\n", getpid());
        printf("pid of parent: %d\n", getppid());
        printf("x: %d\n", x);
    }else{
        x--;
        printf("In parent\n");
        printf("pid of parent: %d\n", getpid());
        printf("pid of parent's child: %d\n", pid);
        printf("x: %d\n", x);
        sleep(1);
    }

    return 0;
}
