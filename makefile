CC = gcc
CFLAGS=-Wall
CYEAR=-std=c99

weapons:
	
	${CC} ${CFLAGS} -o weapons -O2 ${CYEAR} -pedantic weapons.c

all:
	${CC} ${CFLAGS} -o mathhammer -O2 ${CYEAR} -pedantic weapons.c

clean:
	rm mathhammer weapons

