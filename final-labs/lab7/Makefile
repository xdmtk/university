IDIR = include
CC = gcc
CFLAGS = -I$(IDIR) -Wall -Wextra -g
LIBS = -lrt

MATRIX_GEN_OBJ = matrix_gen.o
MATRIX_ADD_OBJ= matrix_add.o
MATRIX_GEN_SRC = src/matrix_gen.c
MATRIX_ADD_SRC = src/matrix_add.c
MATRIX_GEN_EXEC_NAME = matrix_gen
MATRIX_ADD_EXEC_NAME = matrix_add 

all: matrix_add matrix_gen 

matrix_add: $(MATRIX_ADD_OBJ)
	$(CC) $(CFLAGS) -o $(MATRIX_ADD_EXEC_NAME) $(MATRIX_ADD_OBJ) $(LIBS)
	rm $(MATRIX_ADD_OBJ)

matrix_gen: $(MATRIX_GEN_OBJ)
	$(CC) $(CFLAGS) -o $(MATRIX_GEN_EXEC_NAME) $(MATRIX_GEN_OBJ) $(LIBS)
	rm $(MATRIX_GEN_OBJ)

matrix_add.o: 
	$(CC) $(CFLAGS) -g -c $(MATRIX_ADD_SRC)

matrix_gen.o: 
	$(CC) $(CFLAGS) -g -c $(MATRIX_GEN_SRC)

clean:
	rm -f $(MATRIX_GEN_EXEC_NAME)
	rm -f $(MATRIX_ADD_EXEC_NAME)
	rm -f $(MATRIX_GEN_OBJ)
	rm -f $(MATRIX_ADD_OBJ)
