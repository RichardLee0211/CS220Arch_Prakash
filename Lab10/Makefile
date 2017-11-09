CC:=gcc

# all: ret2libc
all: ret2libc

prelim: prelim.c
	$(CC) -m32 -g prelim.c -o prelim

ret2libc: ret2libc.c get_ebp.S
	$(CC)  -m32 -std=c11 -g ret2libc.c get_ebp.S -o ret2libc

clean:
	rm prelim ret2libc *.o
