CC=gcc
CFLAGS=-g -Wall -I .
OBJECTS=NameList.o lsit.o
DEPS = list.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

name-list: $(OBJECTS)
	$(CC) -o name-list.out $(CFLAGS) $(OBJECTS)