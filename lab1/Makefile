IDIR = include
CC = gcc
CFLAGS = -I$(IDIR) -Wall -Wextra

OBJ = main.o
SRC = src/main.c 
EXEC_NAME = time-4-baby-and-me

time-4-baby-and-me: $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(OBJ)
	rm $(OBJ)

main.o: $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(EXEC_NAME)
	rm -f $(OBJ)
