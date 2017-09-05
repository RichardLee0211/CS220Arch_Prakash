#include<stdio.h>

// this is a function about Fibonacci
// for 64 bit machine, int could be 10^19, and Fib[100] could be 10^20, so I
// would like to create a Fib[100] to score all results of Fibonacci
int isFib(int n){
    int Fib[100] = {0, 1, 1, 0};

    Fib[0] = 0;
    Fib[1] = Fib[2] = 1;

    int i;
    for(i=3; i<=100; i++){
        Fib[i] = Fib[i-1] + Fib[i-2];
        //printf("%d ", Fib[i]);
    }
    for(i=0; Fib[i]<=n; i++);
    if(Fib[i-1] == n)
        return i-1;
    else
        return -1;


}

int main(){
    int n;
    printf("please input your number: ");
    //scanf("%d", n);
    printf("\n result is ");
    printf("%d \n", isFib(13));

    return 0;
}
