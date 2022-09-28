open: open.c
	gcc open.c -o nb

test:
	gcc open.c -o nb && ./nb
test2:
	gcc open.c -o nb && ./nb api.invidious.io

clean:
	rm -f *.o nb
install:
	gcc open.c -o nb && cp nb /usr/bin/nb
uninstall:
	rm -f /usr/bin/nb
