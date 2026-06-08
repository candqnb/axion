CXX := clang++

# Default includes
INCLUDES := -Iinclude

# Source and test files
TEST_SRC := tests/test_matrix.cpp
TEST_OBJ := test_matrix.o
TARGET_TEST := test_matrix

# -------------------
# Development flags
# -------------------
DEBUG_FLAGS := -std=c++20 \
               -Wall -Wextra -Wpedantic \
               -Wshadow -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wold-style-cast \
               -g -O0 -fno-omit-frame-pointer \
               -fsanitize=address,undefined,leak \
               -fstack-protector-all \
               -ftemplate-backtrace-limit=0

# -------------------
# Release flags
# -------------------
RELEASE_FLAGS := -std=c++20 -O2 -DNDEBUG -flto -Wall -Wextra -Wpedantic

# Default: debug build
CXXFLAGS := $(DEBUG_FLAGS) $(INCLUDES)

# -------------------
# Targets
# -------------------
all: debug

# Debug build
debug: CXXFLAGS := $(DEBUG_FLAGS) $(INCLUDES)
debug: $(TARGET_TEST)

# Release build
release: CXXFLAGS := $(RELEASE_FLAGS) $(INCLUDES)
release: clean $(TARGET_TEST)

# Compile test object
$(TEST_OBJ): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link executable
$(TARGET_TEST): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run tests
run-test: debug
	./$(TARGET_TEST)

# Clean build artifacts
clean:
	rm -f *.o $(TARGET_TEST)

.PHONY: all debug release run-test clean
