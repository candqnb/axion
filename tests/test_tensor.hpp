#include "axion/linalg/Matrix.hpp"
#include "axion/linalg/Tensor.hpp"

using namespace axion::linalg;

int test_tensor() {
    Tensor<double> T0;
    Tensor<float> T1(2,1);
    Tensor<float> T2(2, 1, {{1, 3}, {1,4}});
    return 0;
}
