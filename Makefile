CXX := clang++
CXXFLAGS := -std=c++20 -Wall -Wextra -O2 -Iinclude

SRC := src/linalg/Matrix.cpp

LIB_OBJ := Matrix.o

TEST_OBJ := test_matrix.o

TARGET_TEST := test_matrix

all: $(TARGET_TEST)

$(LIB_OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_OBJ): tests/test_matrix.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET_TEST): $(LIB_OBJ) $(TEST_OBJ)
	$(CXX) $^ -o $@

run-test: $(TARGET_TEST)
	./$(TARGET_TEST)

clean:
	rm -f *.o $(TARGET_EXAMPLE) $(TARGET_TEST)

.PHONY: all clean run-example run-test
