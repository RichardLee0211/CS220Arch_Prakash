#include <stdio.h>

void foo(int a)
{
	int x;
	x = a << 2;
	printf("%x\n", x);
}

int main()
{
	foo(10);
	return 0; 
}

