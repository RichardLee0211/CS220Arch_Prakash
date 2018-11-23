#include<iostream>
#include<stdio.h>

int foo(int input){
    if(input == 1)
        return 1;
    return input+foo(input-1);
}

int main(){
    for(int i=0x1; i<0x100; i++){
        if(foo(i) == 0x1485){
            std::cout<<i<<std::endl;
            break;
        }
        // std::cout<<foo(i)<<" \n";
        // printf("%x\n", foo(i));
    }
    return 0;
}
