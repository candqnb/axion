#include "axion/linalg/Tensor.hpp"

#include <iostream>

using namespace axion::linalg;

int main() {

	// float tensor
	Tensor<float> t1({2, 3}, 1.0f);

	std::cout << "Float tensor:\n";
	t1.print();

	t1(0) = 5.0f;
	t1(1) = 2.5f;

	std::cout << "\nAfter modification:\n";
	t1.print();

    // double tensor
    Tensor<long double> t3({3, 4}, 3.0);

	std::cout << "\nDouble tensor:\n";
	t3.print();

	t3(0) = 9.0;
	t3(3) = 4.5;

	std::cout << "\nAfter modification:\n";
	t3.print();

	// long double tensor 
	Tensor<long double> t2({3, 2}, 3.0l);

	std::cout << "\nDouble tensor:\n";
	t2.print();

	t2(0) = 9.0;
	t2(3) = 4.5;

	std::cout << "\nAfter modification:\n";
	t2.print();

	return 0;
}
