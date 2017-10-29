CC = gcc
CFLAGS=-Wall
CYEAR=-std=c99

weapons:
	
	${CC} ${CFLAGS} -o weapons.o -O2 ${CYEAR} -pedantic weapons.c

all:
	${CC} ${CFLAGS} -o mathhammer.o -O2 ${CYEAR} -pedantic weapons.c

clean:
	rm mathhammer.o weapons.o


