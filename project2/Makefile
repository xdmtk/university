

INCLUDE = include/
CC = g++
LIBS = pthread
OUT = dvr
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
        src/handler.cpp \
        src/args.cpp \
        src/topology.cpp \
        src/updater.cpp

all:
	g++ $(SRC) $(FLAGS)