# Make file for RPSLS Program.

OBJS	= main.o rpslsImp.o
CC	= g++ -Wall -pedantic -Wextra -std=c++11 -g

all: main

main: $(OBJS)
	$(CC) -o main $(OBJS)

main.o:	main.cpp rpslsType.h rpslsImp.o
	$(CC) -c main.cpp

rpslsImp.o: rpslsImp.cpp rpslsType.h
	$(CC) -c rpslsImp.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS)

