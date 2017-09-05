#include<stdio.h>



// oneBit10[]
// 0 zOrE 2
// 1 OnE 2
// 2 twO 1
// 3 thrEE 2
// 4 fOUr 2
// 5 fIvE 2
// 6 sIx 1
// 7 sEvEn 2
// 8 EIght 2
// 9 nInE 2
unsigned int under9(unsigned long num){
    if(num > 9)
        return -1;
    int oneBit10[10] = {2, 2, 1, 2, 2, 2, 1, 2, 2, 2 };
    return oneBit10[num];
}

// twoBit10_1[]
// 10 tEn 1
// 11 ElEvEn 3
// 12 twElvE 2
// 13 thIrtEEn 3
// 14 fOUrtEEn 4
// 15 fIftEEn 3
// 16 sIxtEEn 3
// 17 sEvEntEEn 4
// 18 EightEEn 3
// 19 nInEtEEn 3
unsigned int under19(unsigned long num){
    if(num >19)
        return -1;
    if(num <= 9)
        return under9(num);

    int twoBit10_1[10] = {1, 3, 2, 3, 4, 3, 3, 4, 3, 3};
    return twoBit10_1[num%10];
}

// 2X twEnty 1+oneBit10[X]
// 3X thIrty 1+oneBit10[X]
// 4X fOrty 1+oneBit10[X]
// 5X fIfty 1+oneBit10[X]
// 6X sIxty 1+oneBit10[X]
// 7X sEvEnty 2+oneBit10[X]
// 8X EIghty 2+oneBit10[X]
// 9X nInEty 2+oneBit10[X]
unsigned int under99(unsigned long num){
    if(num>99)
        return -1;
    if(num<=9)
        return under9(num);
    if(num<=19)
        return under19(num);

    //when num is between 20 and 99
    int secBit = num/10;
    int firstBit = num%10;
    int twoBit10_2[10] = {-1, -1, 1, 1, 1, 1, 1, 2, 2, 2};
    if(firstBit == 0)
        return twoBit10_2[secBit];
    else
        return twoBit10_2[secBit] + under9(firstBit);
}

// 1XX OnE hUndrEd 2+2+under99(XX)
// 2XX twO hUndrEd 1+2+under99(XX)
// 3XX thrEE hUndrEd 2+2+under99(XX)
// 4XX oneBit10[4] +2+under99(XX)
// 5XX oneBit10[5] +2+under99(XX)
// 6XX oneBit10[6] +2+under99(XX)
// 7XX oneBit10[7] +2+under99(XX)
// 8XX oneBit10[8] +2+under99(XX)
// 9XX oneBit10[9] +2+under99(XX)
unsigned int under999(unsigned long num){
    if(num>999)
        return -1;
    if(num<=9)
        return under9(num);
    if(num<=19)
        return under19(num);
    if(num<=99)
        return under99(num);

    //when num is bewteen 100 and 999
    int thirdBit = num/100;
    int secBit = num%100 /10;
    int firstBit = num%10;
    if(secBit == 0 && firstBit == 0)
        return under9(thirdBit) + 2;
    else
        return under9(thirdBit) + 2 +under99(num%100);
}

// 1XXX OnE thOUsAnd under9(1) +3 +under999(XXX)
// 2XXX twO thOUsAnd under9(2) +3 +under999(XXX)
// ...
// CCC XXX under999(CCC) +3 +under999(XXX)
unsigned int under999999(unsigned long num){
    if(num>999999)
        return -1;
    if(num<=9)
        return under9(num);
    if(num<=19)
        return under19(num);
    if(num<=99)
        return under99(num);
    if(num<=999)
        return under999(num);

    // when num is between 1000 and 999999
    int top3bit = num/1000;
    if(num%1000 == 0)
        return under999(top3bit) +3;
    else
        return under999(top3bit) +3 +under999(num%1000);
}

// VVV XXXXXX VVV mIllIOn under999(VVV) +3 +under999999(XXXXXX)
unsigned int under999999999(unsigned long num){
    if(num>999999999)
        return -1;
    if(num<=9)
        return under9(num);
    if(num<=19)
        return under19(num);
    if(num<=99)
        return under99(num);
    if(num<=999)
        return under999(num);
    if(num<=999999)
        return under999999(num);

    // when num is between 1,000,000 and 999,999,999
    int top3bit = num/1000000;
    if(num%1000000 == 0)
        return under999(top3bit) +3;
    else
        return under999(top3bit) +3 +under999999(num%1000000);
}

// to count vowels in number between 1,000,000,000 and 0
unsigned int count_vowels(unsigned long num){
    if(num>1000000000)
        return -1;
    if(num<=9)
        return under9(num);
    if(num<=19)
        return under19(num);
    if(num<=99)
        return under99(num);
    if(num<=999)
        return under999(num);
    if(num<=999999)
        return under999999(num);
    // when num is 1,000,000,000
    if(num == 1000000000)
        return under9(1) +3;
    else
        return -1;

}



int main(){
    int num;
    while(1){
        printf("input your number: ");
        scanf("%d", &num);
        printf("%d result is %d \n", num, count_vowels(num));

    }
    return 0;
}
