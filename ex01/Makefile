CC=gcc
CFLAGS=-I .
DEPS = list.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

name-list: list.o NameList.o
	$(CC) -o name-list.out list.o NameList.o -I .