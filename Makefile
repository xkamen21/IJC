CC=gcc
CFLAGS=-O2 -std=c11 -g -Wall -pedantic -lm

binaries=primes primes-i steg-decode

all: $(binaries)

primes: primes.c bit_array.h eratosthenes.c
		$(CC) primes.c $(CFLAGS) -o primes

primes-i: primes.c bit_array.h eratosthenes.c
		$(CC) primes.c $(CFLAGS) -DUSE_INLINE -o primes-i

steg-decode: steg-decode.c bit_array.h eratosthenes.c ppm.c
		$(CC) steg-decode.c $(CFLAGS) -o steg-decode

clean:
	rm $(binaries)
	echo clean done

pack:
	 zip xkamen21.zip *.c *.h Makefile

run: primes primes-i
	clear
	ulimit -S -s 16000 && time ./primes
	ulimit -S -s 16000 && time ./primes-i
