IDIR = include
CC = gcc
CFLAGS = -I$(IDIR) -Wall -Wextra -g
LIBS = 

OBJ = paging.o
SRC = src/paging.c
EXEC_NAME = a.out

all: $(OBJ) 
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(OBJ) $(LIBS)
	rm $(OBJ)

a.out: $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(OBJ) $(LIBS)
	rm $(OBJ)

paging.o: $(SRC)
	$(CC) $(CFLAGS) -g -c $(SRC)

clean:
	rm -f $(EXEC_NAME)
	rm -f $(OBJ)
