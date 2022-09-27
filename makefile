open: open.c
	gcc open.c -o open.o

test:
	gcc open.c -o open.o && ./open.o
test2:
	gcc open.c -o open.o && ./open.o api.invidious.io

clean:
	rm -f open.o
install:
	gcc open.c -o open.o && cp open.o /usr/bin/nb
