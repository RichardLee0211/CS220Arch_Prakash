#include<stdio.h>

/**
 * do not include math.h ??
 * what does you mean by math library
 */
long a4_minus_b4(int a, int b){
    /* return a*a*a*a - b*b*b*b; */
    return (a*a+b*b)*(a*a-b*b);
}

int main(){
    int a, b;
    printf("\n input a:");
    scanf("%d", &a);
    printf("\n input b:");
    scanf("%d", &b);
    printf("result of a^4-b^4: ");
    printf("%ld \n ", a4_minus_b4(a, b));

    return 0;
}
