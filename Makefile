

INCLUDE = include/
CC = g++
LIBS = pthread
OUT = chat
FLAGS = -I$(INCLUDE) -l$(LIBS) -o $(OUT)
SRC = \
        src/main.cpp \
        src/shell.cpp \
        src/utils.cpp \
        src/logger.cpp \
        src/server.cpp \
        src/client.cpp \
        src/signals.cpp \
        src/connector.cpp \
        src/handler.cpp

all:
	g++ $(SRC) $(FLAGS)