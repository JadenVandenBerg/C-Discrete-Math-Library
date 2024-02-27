lib: main.o library.o
	gcc -Wall main.o library.o -lm -o lib

main.o: main.c library.h
	gcc -Wall -std=c99 -c main.c

library.o: library.c library.h
	gcc -Wall -std=c99 -c library.c

clean:
	rm -f *.o lib