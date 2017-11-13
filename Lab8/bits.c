#include<stdio.h>

#include"bits.h"


void print_in_binary(unsigned int x){
    for(int i=31; i>=0; i--){
        if(x & BIT(i))
            printf("1");
        else
            printf("0");
        if(i%4 == 0)
            printf(" ");
    }
    printf("\n");
    return;
}

/**
 * (a) Bits 0 through 11 constitute the PAGE OFFSET
 */
unsigned int get_page_offset(unsigned int address){
    return BF_GET(address, 0, 12);
};

/**
 * (b) Bits 12, 13 and 14 constitute TLB ID.
 */
unsigned int get_tlb_id(unsigned int address){
    return BF_GET(address, 12, 3);
};

/**
 * (d) Bits 24 through 31 constitute TLB Tag.
 */
unsigned int get_tlb_tag(unsigned int address){
    return BF_GET(address, 24, 8);
};

unsigned int set_page_offset (unsigned int address, unsigned int new_offset){
    return BF_SET(address, new_offset, 0, 12);
};
unsigned int set_tlb_id(unsigned int address, unsigned int new_tlb_id){
    return BF_SET(address, new_tlb_id, 12, 3);
};
unsigned int set_tlb_tag(unsigned int address, unsigned int new_tag){
    return BF_SET(address, new_tag, 24, 8);
};
