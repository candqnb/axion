#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <concepts>

namespace axion::linalg {

	template<typename T>
    concept AllowedNumeric = std::floating_point<T>;

	template <AllowedNumeric T>
    class Tensor {

	public:
		Tensor();
		Tensor(std::initializer_list<std::size_t> shape);
		Tensor(std::initializer_list<std::size_t> shape, T value);

		std::size_t rank() const noexcept;
		std::size_t size() const noexcept;

		const std::vector<std::size_t>& shape() const noexcept;

		T& operator()(std::size_t index);
		const T& operator()(std::size_t index) const;

		void print(std::ostream& os = std::cout) const;

	private:
		std::vector<std::size_t> shape_;
		std::vector<T> data_;

		std::size_t flatten_size(std::initializer_list<std::size_t> shape) const;
	};

}

#include "axion/linalg/Tensor.tpp"
