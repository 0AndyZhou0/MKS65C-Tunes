all : test.c linkedlist.h library.h
	gcc -o tunes test.c linkedlist.h library.h

run : ./tunes
	gcc -o tunes test.c linkedlist.h library.h
	./tunes

fix : test.c linkedlist.h
	gcc -g -o tunes test.c linkedlist.h library.h
	gdb tunes
