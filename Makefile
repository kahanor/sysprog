CC=gcc
CFLAGS=-I ex01/

name-list: ex01/list.o ex01/NameList.o
	$(CC) -o ex01/name-list.out ex01/list.o ex01/NameList.o -I ex01/