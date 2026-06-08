/*
  This file contains all tests related to the matrix implementation.
*/

#include "axion/linalg/Matrix.hpp"

#include <cassert>

using namespace axion::linalg;

int main() {

    Matrix A0(2, 2, {
			1.0, 2.0,
			3.0, 4.0
		});

    Matrix A1(2, 2, {
			5.0, 6.0,
			7.0, 8.0
		});

    Matrix A2(3, 2, {
            3.0, 2.0, 3.0,
            5.0, 9.0, 5.0
        });

    Matrix A3(2, 3, {
            9.0, 2.0,
            8.0, 5.0,
            4.0, 1.0
        });

    // Tests for matrix addition
    assert((A0 + A1)(0,0) == 6.0);
    assert((A0 + A1)(0,1) == 8.0);
    assert((A0 + A1)(1,0) == 10.0);
    assert((A0 + A1)(1,1) == 12.0);

    // Tests for the addition assignment operator
    Matrix T0 = A0;
    T0 += A1;

    assert(T0(0,0) == 6.0);
    assert(T0(0,1) == 8.0);
    assert(T0(1,0) == 10.0);
    assert(T0(1,1) == 12.0);

    // Tests for matrix multiplication
    assert((A0 * A1)(0,0) == 19.0);
    assert((A0 * A1)(0,1) == 22.0);
    assert((A0 * A1)(1,0) == 43.0);
    assert((A0 * A1)(1,1) == 50.0);

    Matrix T1 = A0;
    T1 *= 5.0;

    assert(T1(0,0) == 5.0);
    assert(T1(0,1) == 10.0);
    assert(T1(1,0) == 15.0);
    assert(T1(1,1) == 20.0);

    // Tests for Hadamard operation
    assert((A0.hadamard(A1))(0,0) == 5.0);
    assert((A0.hadamard(A1))(0,1) == 12.0);
    assert((A0.hadamard(A1))(1,0) == 21.0);
    assert((A0.hadamard(A1))(1,1) == 32.0);
    
    return 0;
}
