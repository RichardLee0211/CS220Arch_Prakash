#include<stdio.h>

unsigned long swap_bytes(unsigned long someInt){
    unsigned long byte1 = someInt & 0x00000000000000FF;
    unsigned long byte2 = someInt & 0x000000000000FF00;
    unsigned long byte3 = someInt & 0x0000000000FF0000;
    unsigned long byte4 = someInt & 0x00000000FF000000;
    unsigned long byte5 = someInt & 0x000000FF00000000;
    unsigned long byte6 = someInt & 0x0000FF0000000000;
    unsigned long byte7 = someInt & 0x00FF000000000000;
    unsigned long byte8 = someInt & 0xFF00000000000000;
    /**
     * TODO: report integer literal is too large to be represented in any integer type
     * when use 0xFF00000000000000U or 0x1F00000000000000U
     * maybe first 4 bits has special meaning for unsigned 64 bit Int Literal
     * had been stuck for 2 hours
     */

    unsigned long newInt = (byte1 << 8) | (byte2 >> 8) |
        (byte3 << 8) | (byte4 >> 8) |
        (byte5 << 8) | (byte6 >> 8) |
        (byte7 << 8) | (byte8 >> 8);
    return newInt;
}

int main(){
    unsigned long someInt;
    while(1){
        printf("\nthis is testMain of swap_bytes()");
        printf("\ninput 0 to exit.");
        printf("\nplease input your number: ");
        scanf("%lx", &someInt);
        if(someInt == 0) return -1;
        printf("result is: %#lx", swap_bytes(someInt));
    }


    return 0;
}
