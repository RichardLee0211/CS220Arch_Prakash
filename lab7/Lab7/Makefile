all: driver

driver: driver.c reverse.S
	gcc driver.c reverse.S -o2 -m32 -std=c89 -g -o driver

clean:
	rm -f driver

run:
	./driver
