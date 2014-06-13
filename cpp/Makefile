SRC_DIR	=	src
OBJ_DIR	=	obj
BIN_DIR	=	bin

BIN = $(BIN_DIR)/cacm_exacto $(BIN_DIR)/cacm_goloso $(BIN_DIR)/cacm_busq_local $(BIN_DIR)/cacm_grasp $(BIN_DIR)/cacm_tester

all: init $(BIN)

$(OBJ_DIR)/cacm.o: $(SRC_DIR)/cacm.cpp $(SRC_DIR)/cacm.h
	g++ -c -o $@ $(SRC_DIR)/cacm.cpp

$(OBJ_DIR)/cacm_exacto_main.o: $(SRC_DIR)/cacm_exacto_main.cpp $(SRC_DIR)/cacm.h
	g++ -c -o $@ $<

$(OBJ_DIR)/cacm_goloso_main.o: $(SRC_DIR)/cacm_goloso_main.cpp $(SRC_DIR)/cacm.h
	g++ -c -o $@ $<

$(OBJ_DIR)/cacm_busq_local_main.o: $(SRC_DIR)/cacm_busq_local_main.cpp $(SRC_DIR)/cacm.h
	g++ -c -o $@ $<
	
$(OBJ_DIR)/cacm_grasp_main.o: $(SRC_DIR)/cacm_grasp_main.cpp $(SRC_DIR)/cacm.h
	g++ -c -o $@ $<

$(OBJ_DIR)/cacm_goloso_resolver.o: $(SRC_DIR)/cacm_goloso_resolver.cpp $(SRC_DIR)/cacm_goloso.h
	g++ -c -o $@ $<

$(OBJ_DIR)/cacm_exacto_resolver.o: $(SRC_DIR)/cacm_exacto_resolver.cpp $(SRC_DIR)/cacm_exacto.h
	g++ -c -o $@ $<

$(OBJ_DIR)/cacm_busq_local_resolver.o: $(SRC_DIR)/cacm_busq_local_resolver.cpp $(SRC_DIR)/cacm_busq_local.h
	g++ -c -o $@ $<
	
$(OBJ_DIR)/cacm_grasp_resolver.o: $(SRC_DIR)/cacm_grasp_resolver.cpp $(SRC_DIR)/cacm_grasp.h
	g++ -c -o $@ $<

$(OBJ_DIR)/cacm_tester.o: $(SRC_DIR)/cacm_tester.cpp $(SRC_DIR)/cacm.h $(SRC_DIR)/cacm_goloso.h $(SRC_DIR)/cacm_exacto.h $(SRC_DIR)/cacm_busq_local.h $(SRC_DIR)/cacm_grasp.h
	g++ -c -o $@ $<

$(BIN_DIR)/cacm_exacto: $(OBJ_DIR)/cacm.o $(OBJ_DIR)/cacm_exacto_main.o $(OBJ_DIR)/cacm_exacto_resolver.o
	g++ -o $@ $^

$(BIN_DIR)/cacm_goloso: $(OBJ_DIR)/cacm.o $(OBJ_DIR)/cacm_goloso_main.o $(OBJ_DIR)/cacm_goloso_resolver.o
	g++ -o $@ $^

$(BIN_DIR)/cacm_busq_local: $(OBJ_DIR)/cacm.o $(OBJ_DIR)/cacm_busq_local_main.o $(OBJ_DIR)/cacm_goloso_resolver.o $(OBJ_DIR)/cacm_busq_local_resolver.o
	g++ -o $@ $^
	
$(BIN_DIR)/cacm_grasp: $(OBJ_DIR)/cacm.o $(OBJ_DIR)/cacm_grasp_main.o $(OBJ_DIR)/cacm_busq_local_resolver.o $(OBJ_DIR)/cacm_grasp_resolver.o $(OBJ_DIR)/cacm_goloso_resolver.o 
	g++ -o $@ $^
	
$(BIN_DIR)/cacm_tester: $(OBJ_DIR)/cacm.o $(OBJ_DIR)/cacm_exacto_resolver.o $(OBJ_DIR)/cacm_busq_local_resolver.o $(OBJ_DIR)/cacm_grasp_resolver.o $(OBJ_DIR)/cacm_goloso_resolver.o $(OBJ_DIR)/cacm_tester.o
	g++ -o $@ $^

.PHONY: init clean wipe

init:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR)/*

wipe:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
