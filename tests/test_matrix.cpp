#include "linalg/Matrix.hpp"

#include <cassert>

using namespace axion::linalg;

int main() {

    Matrix A(2, 2, {
			1.0, 2.0,
			3.0, 4.0
		});

    Matrix B(2, 2, {
			5.0, 6.0,
			7.0, 8.0
		});

    Matrix C = A + B;

    assert(C(0, 0) == 6.0);
    assert(C(1, 1) == 12.0);

    Matrix D = A * B;

    assert(D(0, 0) == 19.0);
    assert(D(0, 1) == 22.0);
    assert(D(1, 0) == 43.0);
    assert(D(1, 1) == 50.0);

    Matrix E = A + 5.0;

    assert(E(0,0) == 6.0); 
    assert(E(0,1) == 7.0);
    assert(E(1,0) == 8.0);
    assert(E(1,1) == 9.0);

    Matrix F = A - 5.0;

    assert(F(0,0) == -4.0); 
    assert(F(0,1) == -3.0);
    assert(F(1,0) == -2.0);
    assert(F(1,1) == -1.0);

    Matrix G = A * 5;

    assert(G(0,0) == 5.0);
    assert(G(0,1) == 10.0);
    assert(G(1,0) == 15.0);
    assert(G(1,1) == 20.0);

    return 0;
}
