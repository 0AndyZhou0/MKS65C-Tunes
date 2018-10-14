all : test.c linkedlist.h
	gcc -o tunes test.c linkedlist.h

run : tunes
	./tunes
