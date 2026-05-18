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

    return 0;
}
