SRC_DIR	=	src
OBJ_DIR	=	obj
BIN_DIR	=	bin

BIN = $(BIN_DIR)/exacto $(BIN_DIR)/goloso $(BIN_DIR)/busq_local

all: init $(BIN)

$(OBJ_DIR)/cacm.o: $(SRC_DIR)/cacm.cpp $(SRC_DIR)/cacm.h
	g++ -c -o $(OBJ_DIR)/cacm.o $(SRC_DIR)/cacm.cpp

$(OBJ_DIR)/exacto.o: $(SRC_DIR)/exacto.cpp $(SRC_DIR)/cacm.h
	g++ -c -o $(OBJ_DIR)/exacto.o $(SRC_DIR)/exacto.cpp

$(OBJ_DIR)/goloso.o: $(SRC_DIR)/goloso.cpp $(SRC_DIR)/cacm.h
	g++ -c -o $(OBJ_DIR)/goloso.o $(SRC_DIR)/goloso.cpp

$(OBJ_DIR)/goloso_resolver.o: $(SRC_DIR)/goloso_resolver.cpp $(SRC_DIR)/cacm_goloso.h
	g++ -c -o $(OBJ_DIR)/goloso_resolver.o $(SRC_DIR)/goloso_resolver.cpp

$(OBJ_DIR)/exacto_resolver.o: $(SRC_DIR)/exacto_resolver.cpp $(SRC_DIR)/cacm_exacto.h
	g++ -c -o $(OBJ_DIR)/exacto_resolver.o $(SRC_DIR)/exacto_resolver.cpp

$(OBJ_DIR)/busq_local.o: $(SRC_DIR)/busq_local.cpp $(SRC_DIR)/cacm.h
	g++ -c -o $(OBJ_DIR)/busq_local.o $(SRC_DIR)/busq_local.cpp

$(BIN_DIR)/exacto: $(OBJ_DIR)/cacm.o $(OBJ_DIR)/exacto.o $(OBJ_DIR)/exacto_resolver.o
	g++ -o $(BIN_DIR)/exacto $(OBJ_DIR)/cacm.o $(OBJ_DIR)/exacto.o $(OBJ_DIR)/exacto_resolver.o

$(BIN_DIR)/goloso: $(OBJ_DIR)/cacm.o $(OBJ_DIR)/goloso.o $(OBJ_DIR)/goloso_resolver.o
	g++ -o $(BIN_DIR)/goloso $(OBJ_DIR)/cacm.o $(OBJ_DIR)/goloso.o $(OBJ_DIR)/goloso_resolver.o

$(BIN_DIR)/busq_local: $(OBJ_DIR)/cacm.o $(OBJ_DIR)/busq_local.o $(OBJ_DIR)/goloso_resolver.o
	g++ -o $(BIN_DIR)/busq_local $(OBJ_DIR)/cacm.o $(OBJ_DIR)/busq_local.o $(OBJ_DIR)/goloso_resolver.o

.PHONY: init clean wipe

init:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR)/*

wipe:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)