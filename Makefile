#---------------------------------------------------------------------
# Arquivo	    : main.cpp
# Conteudo	    : programa de avaliacao do TAD HEADERS
# Autor	    : Marcelo Andrade
# Historico	: 2022-11-26
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#			: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/headers.o
HDRS = $(INC)/headers.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

all: mem

mem: $(EXE)
	
$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/tp3 $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/headers.o: $(HDRS) $(SRC)/headers.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/headers.o $(SRC)/headers.cpp 

clean:
	rm $(EXE) $(OBJS)