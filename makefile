
APP_NAME = geometry
LIB_NAME = libgeometry
TEST_NAME = test

CFLAGS = -Wall -Werror
CPPFLAGS = -I src -MP -MMD
LBOFLAGS = -lm

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = bin/geometry
TEST_PATH = bin/test
LIB_PATH = obj/src/libgeometry/libgeometry.a

SRC_EXT = c

APP_SOURCES = $(shell find src/geometry -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

TEST_SOURCES = $(shell find test -name '*.$(SRC_EXT)')
TEST_OBJECTS = $(TEST_SOURCES:test/%.c=obj/test/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d) 

.PHONY: test clean
all: bin/geometry

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LBOFLAGS) $(LDLIBS) -lm

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -I thirdparty $< -o $@ -lm



test: $(TEST_PATH)

-include $(DEPS)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CC) -I thirdparty/ $(CPPFLAGS) $(TEST_OBJECTS) $(LIB_OBJECTS) -o $@ $(LBOFLAGS)




.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH) $(TEST_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
