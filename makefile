	LIB_DIR = src/lib/
	LIB_TEST = test/
	LIB_MAIN = src/main/
	CC = gcc
	AR = ar rc
	FLAG = -lm -o
	O_FLAG_CALC = -Wall -Wextra -I src -c -MP -MMD
	O_FLAG_TEST = -Wall -Wextra -I thirdparty -I src -c -MP -MMD
	BIN = bin/
	OBJ_LIB = obj/$(LIB_DIR)
	OBJ_MAIN = obj/$(LIB_MAIN)
	OBJ_TEST = obj/$(LIB_TEST)

	all: $(BIN)geometry.exe $(BIN)tests.exe
	calc: $(BIN)geometry.exe

	test: $(BIN)tests.exe

	$(BIN)geometry.exe: $(BIN)calc.a
	$(CC) $(BIN)calc.a $(FLAG) $@

	$(BIN)tests.exe: $(BIN)test.a
	$(CC) $(OBJ_TEST)test_main.o $(OBJ_TEST)test.o $(OBJ_LIB)lib_main_chek.o $(FLAG) $@

	$(BIN)test.a: $(OBJ_TEST)test_main.o $(OBJ_TEST)test.o $(OBJ_LIB)lib_main_chek.o
	$(AR) $@ $(OBJ_TEST)test_main.o $(OBJ_TEST)test.o $(OBJ_LIB)lib_main_chek.o

	$(BIN)calc.a: $(OBJ_LIB)lib_calc_trans.o $(OBJ_LIB)lib_main_chek.o $(OBJ_MAIN)geometry_lab4.o
	$(AR) $@ $(OBJ_LIB)lib_calc_trans.o $(OBJ_LIB)lib_main_chek.o $(OBJ_MAIN)geometry_lab4.o

	$(OBJ_TEST)test_main.o: $(LIB_TEST)test_main.c
	$(CC) $(O_FLAG_TEST) $(LIB_TEST)test_main.c -o $@

	$(OBJ_TEST)test.o: $(LIB_TEST)test.c
	$(CC) $(O_FLAG_TEST) $(LIB_TEST)test.c -o $@

	$(OBJ_MAIN)geometry_lab4.o: $(LIB_MAIN)geometry_lab4.c
	$(CC) $(O_FLAG_CALC) $(LIB_MAIN)geometry_lab4.c $(FLAG) $@

	$(OBJ_LIB)lib_calc_trans.o: $(LIB_DIR)lib_calc_trans.c
	$(CC) $(O_FLAG_CALC) $(LIB_DIR)lib_calc_trans.c $(FLAG) $@

	$(OBJ_LIB)lib_main_chek.o: $(LIB_DIR)lib_main_chek.c
	$(CC) $(O_FLAG_CALC) $(LIB_DIR)lib_main_chek.c $(FLAG) $@

	.PHONY: clean
	clean:
	$(RM) $(OBJ_LIB)*.o $(OBJ_MAIN)*.o $(OBJ_TEST)*.o
	$(RM) $(OBJ_LIB)*.d $(OBJ_MAIN)*.d $(OBJ_TEST)*.d
	$(RM) $(BIN)*.exe $(BIN)*.a
