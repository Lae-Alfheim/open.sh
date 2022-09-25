open: open.c
	gcc open.c -o open.o

test:
	gcc open.c -o open.o && ./open.o

clean:
	rm -f open.o
install:
	gcc open.c -o open.o && cp open.o /usr/bin/nb
