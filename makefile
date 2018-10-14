all : test.c linkedlist.h
	gcc -o tunes test.c linkedlist.h

run : ./tunes
	gcc -o tunes test.c linkedlist.h
	./tunes
fix : test.c linkedlist.h
	gcc -g -o tunes test.c linkedlist.h
	gdb tunes
