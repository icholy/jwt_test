CC=clang

all: main

main: main.o hmac.o sha2.o base64.o
	$(CC) main.o hmac.o sha2.o base64.o -o main

main.o: main.c
	$(CC) -Wall -Wno-pointer-sign -c main.c -o main.o

hmac.o: hmac_sha2.c hmac_sha2.h
	$(CC) -Wall -c hmac_sha2.c -o hmac.o

sha2.o: sha2.c sha2.h
	$(CC) -Wall -c sha2.c -o sha2.o

base64.o: base64.c base64.h
	$(CC) -Wall -c base64.c -o base64.o


clean:
	rm -f *.o main
