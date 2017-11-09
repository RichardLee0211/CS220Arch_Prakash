#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

extern uint32_t* get_ebp(void);
extern int system( const char *command );

    /* TASK 1: Get the value of ebp. Make use of the get ebp function you have previously written . */
    /* TASK 2: Overwrite written address with address of system */
    /* TASK 3: Set up the argument to system as a pointer to string ”/bin/bash” */
void ret2libc(int dummy) {
    uint32_t* curr_ebp = get_ebp();
    // curr_ebp[0] ret2libc base
    // curr_ebp[1] ret2libc return address
    // curr_ebp[2] the argument of ret2libc
    curr_ebp [2] = curr_ebp [1];
    curr_ebp[1] = (uint32_t) &system;
    char* str = "/bin/bash";
    curr_ebp[3] = (uint32_t) str;
}

void ret2libc_generic(char *cmd){
    char* str = (char*) malloc(sizeof(cmd));
    // memcpy(str, cmd, sizeof(cmd));
    strcpy(str, cmd);
    uint32_t* curr_ebp = get_ebp();
    curr_ebp[2] = curr_ebp[1];
    curr_ebp[1] = (uint32_t) &system;
    curr_ebp[3] = (uint32_t) str;
}

int main(){
    // ret2libc(0);
    char* cmd = "ls -l";
    ret2libc_generic(cmd);
    printf("Done!\n");
    return 0;
}
