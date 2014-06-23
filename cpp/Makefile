SRC_DIR	=	src
OBJ_DIR	=	obj
BIN_DIR	=	bin

BIN = $(BIN_DIR)/cacm_exacto $(BIN_DIR)/cacm_goloso $(BIN_DIR)/cacm_busq_local $(BIN_DIR)/cacm_grasp $(BIN_DIR)/cacm_tester $(BIN_DIR)/cacm_medir

all: init $(BIN)

$(OBJ_DIR)/cacm.o: $(SRC_DIR)/cacm.cpp $(SRC_DIR)/cacm.h
	g++ -c -o $@ $(SRC_DIR)/cacm.cpp

$(OBJ_DIR)/cacm_exacto_resolver.o: $(SRC_DIR)/cacm_exacto_resolver.cpp $(SRC_DIR)/cacm.h $(SRC_DIR)/cacm_exacto.h
	g++ -c -o $@ $<

$(OBJ_DIR)/cacm_dijkstra_resolver.o: $(SRC_DIR)/cacm_dijkstra_resolver.cpp $(SRC_DIR)/cacm.h $(SRC_DIR)/cacm_dijkstra.h
	g++ -c -o $@ $<

$(OBJ_DIR)/cacm_goloso_resolver.o: $(SRC_DIR)/cacm_goloso_resolver.cpp $(SRC_DIR)/cacm.h $(SRC_DIR)/cacm_dijkstra.h $(SRC_DIR)/cacm_goloso.h
	g++ -c -o $@ $<

$(OBJ_DIR)/cacm_busq_local_resolver.o: $(SRC_DIR)/cacm_busq_local_resolver.cpp $(SRC_DIR)/cacm.h $(SRC_DIR)/cacm_dijkstra.h $(SRC_DIR)/cacm_goloso.h $(SRC_DIR)/cacm_busq_local.h
	g++ -c -o $@ $<
	
$(OBJ_DIR)/cacm_grasp_resolver.o: $(SRC_DIR)/cacm_grasp_resolver.cpp $(SRC_DIR)/cacm.h $(SRC_DIR)/cacm_goloso.h $(SRC_DIR)/cacm_busq_local.h $(SRC_DIR)/cacm_grasp.h
	g++ -c -o $@ $<

$(BIN_DIR)/cacm_exacto: $(SRC_DIR)/cacm_exacto_main.cpp $(OBJ_DIR)/cacm.o $(OBJ_DIR)/cacm_exacto_resolver.o
	g++ -o $@ $^

$(BIN_DIR)/cacm_goloso: $(SRC_DIR)/cacm_goloso_main.cpp $(OBJ_DIR)/cacm.o $(OBJ_DIR)/cacm_dijkstra_resolver.o $(OBJ_DIR)/cacm_goloso_resolver.o
	g++ -o $@ $^

$(BIN_DIR)/cacm_busq_local: $(SRC_DIR)/cacm_busq_local_main.cpp $(OBJ_DIR)/cacm.o $(OBJ_DIR)/cacm_dijkstra_resolver.o $(OBJ_DIR)/cacm_goloso_resolver.o $(OBJ_DIR)/cacm_busq_local_resolver.o
	g++ -o $@ $^
	
$(BIN_DIR)/cacm_grasp: $(SRC_DIR)/cacm_grasp_main.cpp $(OBJ_DIR)/cacm.o $(OBJ_DIR)/cacm_dijkstra_resolver.o $(OBJ_DIR)/cacm_goloso_resolver.o $(OBJ_DIR)/cacm_busq_local_resolver.o $(OBJ_DIR)/cacm_grasp_resolver.o
	g++ -o $@ $^
	
$(BIN_DIR)/cacm_tester: $(SRC_DIR)/cacm_tester.cpp $(OBJ_DIR)/cacm.o $(OBJ_DIR)/cacm_exacto_resolver.o $(OBJ_DIR)/cacm_dijkstra_resolver.o $(OBJ_DIR)/cacm_goloso_resolver.o $(OBJ_DIR)/cacm_busq_local_resolver.o $(OBJ_DIR)/cacm_grasp_resolver.o
	g++ -o $@ $^

$(BIN_DIR)/cacm_medir: $(SRC_DIR)/cacm_medir.cpp $(OBJ_DIR)/cacm.o $(OBJ_DIR)/cacm_exacto_resolver.o $(OBJ_DIR)/cacm_dijkstra_resolver.o $(OBJ_DIR)/cacm_goloso_resolver.o $(OBJ_DIR)/cacm_busq_local_resolver.o $(OBJ_DIR)/cacm_grasp_resolver.o
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
