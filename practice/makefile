# Makefile for executable cstacktest

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -ansi -pedantic -Wall -Wfatal-errors -g

# ****************************************************
# Entries to bring the executable up to date

cstacktest: cstacktest.o cstack.o
	$(CC) $(CFLAGS) -o cstacktest cstacktest.o cstack.o

cstacktest.o: cstacktest.c cstack.h
	$(CC) $(CFLAGS) -c cstacktest.c

cstack.o: cstack.c cstack.h
	$(CC) $(CFLAGS) -c cstack.c
