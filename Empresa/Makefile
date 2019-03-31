# Makefile da disciplina Linguagem de Programação I
# Alunos: Letícia Pinheiro e odilon Júlio

CC = g++
PROG = $(BIN)/Empresa

OBJ = ./build
SRC = ./src
BIN = ./bin
INC = ./include

CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

OBJS =  $(OBJ)/data.o $(OBJ)/funcionario.o $(OBJ)/empresa.o $(OBJ)/cadastro.o $(OBJ)/main.o

all: $(PROG)
	$(PROG)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

$(OBJ)/cadastro.o: $(INC)/cadastro.h
	$(CC) $(CPPFLAGS) -c $(SRC)/cadastro.cpp -o $(OBJ)/cadastro.o

$(OBJ)/funcionario.o: $(INC)/funcionario.h
	$(CC) $(CPPFLAGS) -c $(SRC)/funcionario.cpp -o $(OBJ)/funcionario.o

$(OBJ)/empresa.o: $(INC)/empresa.h
	$(CC) $(CPPFLAGS) -c $(SRC)/empresa.cpp -o $(OBJ)/empresa.o

$(OBJ)/data.o: $(INC)/data.h
	$(CC) $(CPPFLAGS) -c $(SRC)/data.cpp -o $(OBJ)/data.o


$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o



clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*