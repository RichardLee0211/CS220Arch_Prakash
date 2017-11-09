#include<stdio.h>
#include<stdint.h>

extern uint32_t* get_ebp(void);

void ret2libc(int dummy) {
    /* TASK 1: Get the value of ebp. Make use of the get ebp function you have previously written . */
    /* TASK 2: Overwrite written address with address of system */
    /* TASK 3: Set up the argument to system as a pointer to string ”/bin/bash” */
}

int main(){
    ret2libc(0);
    printf("Done!/n");
    return 0;
}
