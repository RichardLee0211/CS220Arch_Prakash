#include<stdio.h>

#include"bits.h"

int test(){
    unsigned int val = 0x1111;
    print_in_binary(val);
    print_in_binary(BIT(5));
    print_in_binary(BIT_SET(val, BIT(5)));
    print_in_binary(BIT_CLEAR(val, BIT(4)));

    uint val2 = 0x0;
    uint fullmask = 0xffff;
    if(IS_SET_ANY(val2, fullmask))
        printf("IS_SET_ANY\n");
    else
        printf("no IS_SET_ANY\n");

    if(IS_CLEAR_ANY(fullmask, fullmask))
        printf("IS_CLEAR_ANY\n");
    else
        printf("no IS_CLEAR_ANY\n");

    print_in_binary(BIT_MASK(4));
    print_in_binary(BF_MASK(4, 4));
    print_in_binary(BF_PREP(0xf0, 4, 4));
    print_in_binary(BF_GET(0xffff, 4, 2));
    print_in_binary(BF_GET_WITH_MASK(0xffff, BF_MASK(8, 4)));
    print_in_binary(BF_SET_WITH_MASK(val2, 0xffff, BF_MASK(0, 4)));
    print_in_binary(BF_SET(val2, 0xffff, 8, 4));
    return 0;
}

int main(){
    uint address = 0xf712c0d0;
    printf("before: \n");
    print_in_binary(address);
    printf("\n");
    // change to 0x1a3
    printf("page offset: \n");
    print_in_binary(get_page_offset(address));
    print_in_binary(address = set_page_offset(address, 0x1a3));
    printf("\n");
    // change to 0x0
    printf("TLB ID: \n");
    print_in_binary(get_tlb_id(address));
    print_in_binary(address = set_tlb_id(address, 0x0));
    printf("\n");
    // change to 0x8400
    printf("TLB TAG: \n");
    print_in_binary(get_tlb_tag(address));
    print_in_binary(address = set_tlb_tag(address, 0x8400)); // but TLB TAG only have 8 bits
    printf("\n");

    printf("after: \n");
    print_in_binary(address);

    return 0;
}
