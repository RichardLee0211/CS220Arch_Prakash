#include<stdio.h>

struct bad_struct{
    short s1;
    long l1;
    short s2;
};

struct good_struct{
    short s1;
    short s2;
    long l1;
};

union unit{
    char c;
    int i;
    long l;
};

int main(){
    struct good_struct gs;
    struct bad_struct bs;
    printf("size of good_struct: %lu \n", sizeof(gs));
    printf("size of bad_struct: %lu \n", sizeof(bs));
    printf("address of good_struct: %p\n", &gs);
    printf("address of bad_struct: %p\n", &bs);

    union unit u;
    printf("size of u: %lu \n", sizeof(u));
    printf("address of u.c: %p\n", &u.c);
    printf("address of u.i: %p\n", &u.i);
    printf("address of u.l: %p\n", &u.l);

    scanf("%lu", &u.l);
    printf("size of u now: %lu\n", sizeof(u));
    printf("address of u.c now: %p\n", &u.c);
    printf("address of u.i now: %p\n", &u.i);
    printf("address of u.l now: %p\n", &u.l);

    return 0;


}
