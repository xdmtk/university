IDIR = include
CC = gcc
CFLAGS = -I$(IDIR) -Wall -Wextra

OBJ = catcher.o
SRC = src/catcher.c
EXEC_NAME = catcher

all: $(OBJ) 
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(OBJ)
	rm $(OBJ)

catcher: $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(OBJ)
	rm $(OBJ)

catcher.o: $(SRC)
	$(CC) $(CFLAGS) -g -c $(SRC)

clean:
	rm -f $(EXEC_NAME)
	rm -f $(OBJ)
