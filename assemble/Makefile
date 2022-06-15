CC = gcc
TARGET = notesearch,notetaker
OBJ = notesearch.c,notetaker.c

%.o :%.c
	$(CC) -c $< 


.clean:
	rm -rf *.o

hacking.o : hacking.c
notesearch.o: notesearch.c hacking.o
notetaker.o : notetaker.c hacking.o