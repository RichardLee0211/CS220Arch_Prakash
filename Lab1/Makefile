# $(error No commands added yet to build $@ !)
all:
	$(info use `make loop` or `make buggy`.)

loop: loop.c
	gcc -Wall loop.c -o loop.out

buggy: buggy.c
	gcc -std=c89 -fno-stack-protector -w -g -o buggy buggy.c

.PHONY: clean
clean:
	rm -fv loop buggy
	rm -fv *~ #*#
