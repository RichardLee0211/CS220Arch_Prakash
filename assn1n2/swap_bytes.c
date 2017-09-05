#include<stdio.h>

unsigned long swap_bytes(unsigned long someInt){

unsigned long byte1 = someInt & 0x000000000000000FF;
unsigned long byte2 = someInt & 0x0000000000000FF00;
unsigned long byte3 = someInt & 0x0000000000FF00000;
unsigned long byte4 = someInt & 0x00000000FF0000000;

unsigned long byte5 = someInt & 0x000000FF000000000;
unsigned long byte6 = someInt & 0x0000FF00000000000;
unsigned long byte7 = someInt & 0x00FF0000000000000;
unsigned long byte8 = someInt & 0xFF000000000000000;

unsigned long newInt = (byte1 << 8) | (byte2 >> 8) |
    (byte3 << 8) | (byte4 >> 8) |
    (byte5 << 8) | (byte6 >> 8) |
    (byte7 << 8) | (byte8 >> 8);
return newInt;
}

int main(){

    return 0;
}
