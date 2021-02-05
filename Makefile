TARGET_EXEC = out

SRC_DIR := ./src
BUILD_DIR := ./build
INCLUDE_DIRS := ./include
LIB_DIRS :=

SRC_FILES := $(shell find $(SRC_DIR) -name *.cpp)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

INCLUDE_FLAGS := $(addprefix -I,$(INCLUDE_DIRS))
LIB_FLAGS := $(addprefix -L,$(LIB_DIRS))

CPPFLAGS := $(INCLUDE_FLAGS)
LDFLAGS := $(LIB_FLAGS)
CXX := g++

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJ_FILES)
	@$(CXX) $(OBJ_FILES) -o $@
	@./$(BUILD_DIR)/$(TARGET_EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY = clean
clean:
	@rm -r $(BUILD_DIR)
	@mkdir $(BUILD_DIR)
