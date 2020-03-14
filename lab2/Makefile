IDIR = include
CC = gcc
CFLAGS = -I$(IDIR) -Wall -Wextra

LAUNCH_OBJ = launch.o
LAUNCH_SRC = src/launch.c
LAUNCH_EXEC_NAME = launch

TUBE_OBJ = tube.o
TUBE_SRC = src/tube.c
TUBE_EXEC_NAME = tube

all: $(LAUNCH_OBJ) $(TUBE_OBJ)
	$(CC) $(CFLAGS) -o $(LAUNCH_EXEC_NAME) $(LAUNCH_OBJ)
	$(CC) $(CFLAGS) -o $(TUBE_EXEC_NAME) $(TUBE_OBJ)
	rm $(LAUNCH_OBJ)
	rm $(TUBE_OBJ)

launch: $(LAUNCH_OBJ)
	$(CC) $(CFLAGS) -o $(LAUNCH_EXEC_NAME) $(LAUNCH_OBJ)
	rm $(LAUNCH_OBJ)

tube: $(TUBE_OBJ)
	$(CC) $(CFLAGS) -o $(TUBE_EXEC_NAME) $(TUBE_OBJ)
	rm $(TUBE_OBJ)

launch.o: $(LAUNCH_SRC)
	$(CC) $(CFLAGS) -g -c $(LAUNCH_SRC)

tube.o: $(TUBE_SRC)
	$(CC) $(CFLAGS) -g -c $(TUBE_SRC)

clean:
	rm -f $(LAUNCH_EXEC_NAME)
	rm -f $(LAUNCH_OBJ)
	rm -f $(TUBE_EXEC_NAME)
	rm -f $(TUBE_OBJ)
