#
# makefile for image and  utilities C library
#
#

CC = gcc -std=gnu99
FLAGS = -Wall
INCLUDES = -lm


utilsTesterCmocka: utils.o utilsTesterCmocka.c
	$(CC) $(FLAGS) utils.o utilsTesterCmocka.c -o utilsTesterCmocka $(INCLUDES)  -L/opt/homebrew/opt/cmocka/lib -lcmocka

# utilsTesterCmockaWorkaround: utils.o utilsTesterCmocka.c
# 	$(CC) $(FLAGS) utils.o utilsTesterCmocka.c -o utilsTesterCmocka $(INCLUDES) -L. -l :libcmocka-static.a

utils.o: utils.c utils.h
	$(CC) $(FLAGS) $(INCLUDES) -c utils.c -o utils.o

clean:
	rm -f *~ *.o

