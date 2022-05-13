TAEGET = elfsample
CC = gcc
OPT1 = -Wall
OPT2 = -c
OPT3 = -o

$(TAEGET):elfsample.o main.o
	$(CC) $? $(OPT1) $(OPT3) $@

*.o:*.c
	$(CC) $(OPT1) $<
	


