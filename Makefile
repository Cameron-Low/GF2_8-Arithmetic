TARGET_EXEC = out

SRC_DIR := ./src
BUILD_DIR := ./bin
LIB_DIR := ./lib

INCLUDE_DIRS := ./include
LIB_DIRS :=

SRC_FILES := $(shell find $(SRC_DIR) -name *.cpp)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

INCLUDE_FLAGS := $(addprefix -I,$(INCLUDE_DIRS))
LIB_FLAGS := $(addprefix -L,$(LIB_DIRS))

CPPFLAGS := $(INCLUDE_FLAGS) -std=c++11
LDFLAGS := $(LIB_FLAGS)
CXX := g++

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJ_FILES)
	@$(CXX) $(OBJ_FILES) -o $@
	@./$(BUILD_DIR)/$(TARGET_EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY = build
build: $(OBJ_FILES)
	@ar rcs $(LIB_DIR)/libaesgf28.a $^

.PHONY = clean
clean:
	@rm -r $(BUILD_DIR)
	@rm -r $(LIB_DIR)
	@mkdir $(BUILD_DIR)
	@mkdir $(LIB_DIR)
