CXX := clang++

# Default includes
INCLUDES := -Iinclude

# Test sources and objects
TEST_SRCS := $(wildcard tests/*.cpp)
TEST_OBJS := $(TEST_SRCS:.cpp=.o)

TARGET_TEST := tests/test

# Development flags
DEBUG_FLAGS := -std=c++20 \
               -Wall -Wextra -Wpedantic \
               -Wshadow -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wold-style-cast \
               -g -O0 -fno-omit-frame-pointer \
               -fsanitize=address,undefined,leak \
               -fstack-protector-all \
               -ftemplate-backtrace-limit=0

# Release flags
RELEASE_FLAGS := -std=c++20 -O2 -DNDEBUG -flto -Wall -Wextra -Wpedantic

# Default: debug build
CXXFLAGS := $(DEBUG_FLAGS) $(INCLUDES)

# Targets
all: debug

# Debug build
debug: CXXFLAGS := $(DEBUG_FLAGS) $(INCLUDES)
debug: $(TARGET_TEST)

# Release build
release: CXXFLAGS := $(RELEASE_FLAGS) $(INCLUDES)
release: clean $(TARGET_TEST)

# Compile each test source
tests/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link executable
$(TARGET_TEST): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run tests
run-test: debug
	./$(TARGET_TEST)

# Clean build artifacts
clean:
	rm -f tests/*.o

.PHONY: all debug release run-test clean
