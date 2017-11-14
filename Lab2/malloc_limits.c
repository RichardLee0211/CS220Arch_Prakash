/* malloc_limits.c */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i =1;
	while(1){
		int *p = (int *) malloc (i* 0x1000);
		if( p == NULL ) break;
		i *= 2;
	}

	return 0;
}
