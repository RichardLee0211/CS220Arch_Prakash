#include<stdio.h>
#include<unistd.h>

int main(){
    int x = 1;
    pid_t pid;
    pid = fork();
    if(pid == 0){
        x++;
        printf("# In child\n");
        printf("# pid : %d\n", getpid());
        printf("# pid of parent: %d\n", getppid());
        printf("# x: %d\n", x);
    }else{
        x--;
        sleep(1);
        printf("In parent\n");
        printf("pid : %d\n", getpid());
        printf("pid of parent: %d\n", getppid());
        printf("pid of child: %d\n", pid);
        printf("x: %d\n", x);
    }

    return 0;
}
