
CC=clang
CFLAGS=-Wall -Wno-pointer-sign


main: main.o hmac.o sha2.o base64.o
	$(CC) $(CFLAGS) main.o hmac.o sha2.o base64.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

hmac.o: hmac_sha2.c hmac_sha2.h
	$(CC) $(CFLAGS) -c hmac_sha2.c -o hmac.o

sha2.o: sha2.c sha2.h
	$(CC) $(CFLAGS) -c sha2.c -o sha2.o

base64.o: base64.c base64.h
	$(CC) $(CFLAGS) -c base64.c -o base64.o

all: main

clean:
	rm -f *.o main
