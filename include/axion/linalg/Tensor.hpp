#pragma once

#include <concepts>
#include <vector>
#include <cstddef>
#include <stdexcept>
#include <initializer_list>

namespace axion::linalg {

    template<typename T>
    concept TensorTypes = std::floating_point<T>;

    template<TensorTypes T>
    class Tensor {
    public:
        Tensor();
        Tensor(std::size_t rows, std::size_t cols);
        Tensor(std::size_t rows, std::size_t cols, std::vector<std::vector<T>> values);

    private:
        std::size_t rows_{};
        std::size_t cols_{};
        std::vector<std::vector<T>> data_;
    };

}

#include "Tensor.tpp"
