CC=gcc
CFLAGS=-Wall -Wextra

bcmp: bcmp.c
	$(CC) $(CFLAGS) bcmp.c -o bcmp
