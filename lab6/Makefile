IDIR = include
CC = gcc
CFLAGS = -I$(IDIR) -Wall -Wextra -g
LIBS = -pthread

MOLE_OBJ = moles.o
SPIRITD_OBJ= spiritd.o
MOLE_SRC = src/moles.c
SPIRITD_SRC = src/spiritd.c
MOLE_EXEC_NAME = mole
SPIRITD_EXEC_NAME = spiritd

all: spiritd moles

spiritd: $(SPIRITD_OBJ)
	$(CC) $(CFLAGS) -o $(SPIRITD_EXEC_NAME) $(SPIRITD_OBJ) $(LIBS)
	rm $(SPIRITD_OBJ)

moles: $(MOLE_OBJ)
	$(CC) $(CFLAGS) -o $(MOLE_EXEC_NAME) $(MOLE_OBJ) $(LIBS)
	rm $(MOLE_OBJ)

spiritd.o: 
	$(CC) $(CFLAGS) -g -c $(SPIRITD_SRC)

moles.o: 
	$(CC) $(CFLAGS) -g -c $(MOLE_SRC)

clean:
	rm -f $(MOLE_EXEC_NAME)
	rm -f $(SPIRITD_EXEC_NAME)
	rm -f $(MOLE_OBJ)
	rm -f $(SPIRITD_OBJ)
