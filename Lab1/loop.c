#include <stdio.h>
#include <time.h>

void forLoop(unsigned int n) {
	unsigned int i;
	for(i = 0; i < n; i++)
		;
}

void whileLoop(unsigned int n) {
	while(n > 0)
		n--;
}

void doWhileLoop(unsigned int n) {
	do { n--; } while (n > 0);
}

int main()
{
    int n = 1000000000;

    clock_t tic = clock();
    
    forLoop(n);
    forLoop(n);
    forLoop(n);
    clock_t tic1 = clock();

    whileLoop(n);
    whileLoop(n);
    whileLoop(n);
    clock_t tic2 = clock();

    doWhileLoop(n);
    doWhileLoop(n);
    doWhileLoop(n);
    clock_t tic3 = clock();


    printf("Elapsed of forLoop: %f seconds\n", (double)(tic1 - tic) / CLOCKS_PER_SEC / 3);
    printf("Elapsed of whileLoop: %f seconds\n", (double)(tic2 - tic1) / CLOCKS_PER_SEC / 3);
    printf("Elapsed of doWhileLoop: %f seconds\n", (double)(tic3 - tic2) / CLOCKS_PER_SEC / 3);

    return 0;
}
