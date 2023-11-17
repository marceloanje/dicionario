#---------------------------------------------------------------------
# Arquivo	: Makefile
# Autor	    : Marcelo Andrade
# Historico	: 2022-11-26
#---------------------------------------------------------------------
# Opções	: make - compila tudo
#			: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
CFLAGS = -Wall -std=c++11

SRCS = main.cpp headers.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = run.out

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
