CC=gcc
CFLAGS=-g -Wall
DEPS=myDynamicPersonList.h
OBJ=myDynamicPersonList.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

personFileReader: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
