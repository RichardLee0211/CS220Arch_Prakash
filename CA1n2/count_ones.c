#include<stdio.h>

unsigned int count_ones(long num){
    int count=0;
    int i=64;/*32或64位比特位*/
    while(i--)
    {
        if((num&1) == 1)count++;
        num=num>>1;
        /*>>右移运算符；右移时负数补1、正数补0，num>>1指右移1位*/
    }
    return count;

}

int main()
{
    long num;
    while(1){
        printf("please input your number: ");
        scanf("%ld",&num);
        printf("count=%d \n", count_ones(num));

    }
    return 0;
}
