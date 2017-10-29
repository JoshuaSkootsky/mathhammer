CC = gcc
CFLAGS=-Wall
CYEAR=-std=c99

mathhammer:
	
	${CC} ${CFLAGS} -o mathhammer.o -O2 ${CYEAR} -pedantic mathhammer.c

all:
	${CC} ${CFLAGS} -o mathhammer.o -O2 ${CYEAR} -pedantic mathhammer.c

clean:
	rm mathhammer.o weapons.o


