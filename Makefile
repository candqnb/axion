CXX := clang++
CXXFLAGS := -std=c++23 -Wall -Wextra -O2 -Iinclude

SRC_DIR := src
TEST_DIR := tests
BUILD_DIR := build

TARGET_TEST := test_runner

# Collect sources
SRC := $(shell find $(SRC_DIR) -name "*.cpp")
TEST_SRC := $(shell find $(TEST_DIR) -name "*.cpp")

# Object mapping
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TEST_OBJ := $(TEST_SRC:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/tests/%.o)

# Default: build + test
all: build test

# BUILD ONLY
build: $(OBJ)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Test build
$(BUILD_DIR)/tests/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link test executable
$(TARGET_TEST): $(OBJ) $(TEST_OBJ)
	$(CXX) $^ -o $@

# Test and run (build + run)
test: $(TARGET_TEST)
	./$(TARGET_TEST)

# CLEAN
clean:
	rm -rf $(BUILD_DIR) $(TARGET_TEST)

.PHONY: all build test clean
