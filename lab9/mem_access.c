#include<stdio.h>
#include<sys/time.h>
#include<fcntl.h>

// #define STEP_SIZE 1024
#define STEP_SIZE 4
#define READ_SIZE 64*1024*1024

int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}

void timeval_print(char *str, struct timeval *tv)
{
    printf("%s %ld sec, %06ld micro sec\n", str, tv->tv_sec, tv->tv_usec);
}


int test_hdd(){
    // FILE * fd;
    int fd;
    char c[READ_SIZE];
	struct timeval tvDiff, tvStart, tvEnd;
    fd = open("file64M", O_RDONLY); /* couldn't find this funciton in C document*/
    /*start timer here */
	gettimeofday(&tvStart, NULL);

    for(int i=0; i< READ_SIZE; i+= STEP_SIZE){
        read(fd, &c[0], STEP_SIZE);
    }

    /* stop timer here */
	gettimeofday(&tvEnd, NULL);
    /* calulate time taken here */
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);
    timeval_print("HDD ACCESS: ", &tvDiff);
    return 0;
}

int main(){
    test_hdd();
    return 0;
}
