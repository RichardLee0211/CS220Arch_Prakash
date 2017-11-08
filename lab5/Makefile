all: main_shared

shared.o: shared.c
	gcc -c -std=c89 -g -Wall shared.c -I$(PWD)

lib/libshared.so: shared.o
	gcc -shared shared.o -o lib/libshared.so

lib/libshared.a: shared.o
	ar rcs lib/libshared.a share.o

main_shared: main.c lib/libshared.so
	gcc -std=c89 -g main.c -I$(PWD) -L$(PWD)/lib -o main_shared -lshared

main_static: main.c lib/libshared.a
	gcc -std=c89 -g main.c -I$(PWD) libshared.a -o main_static

run:
	export LD_LIBRARY_PATH=$(PWD)/lib
	# export LD_LIBRARY_PATH=$PWD/lib
	# when run in bash
	./main_shared
