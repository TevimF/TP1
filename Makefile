#Compilador e flags
CC = g++
CXXFLAGS = -std=c++11 -g -Wall

#Diretorios
INCLUDE_FOLDER = ./include/
SRC_FOLDER = ./src/
OBJ_FOLDER = ./obj/
BIN_FOLDER = ./bin/

#Variáveis de compilação
MAIN = main 
TARGET = tp1.out
SRC = $(wildcard $(SRC_FOLDER)*.cpp) 
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

#Regra para compilar os arquivos .cpp	e transformar em .o
$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I $(INCLUDE_FOLDER)

# Regra para criar a pasta bin e obj, se não existir
$(shell mkdir -p $(BIN_FOLDER))
$(shell mkdir -p $(OBJ_FOLDER))

#Regra padrão para compilar o programa e ir para a pasta obj
#Executa o clean e depois compila
all: clean $(OBJ) 
	$(CC) $(CXXFLAGS) $(OBJ) -o $(BIN_FOLDER)$(TARGET)

#Regra para limpar os arquivos de construção
clean:
	@rm -f $(OBJ_FOLDER)* $(BIN_FOLDER)*
