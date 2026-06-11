#pragma once

#include <concepts>
#include <vector>
#include <cstddef>
#include <stdexcept>
#include <initializer_list>

namespace axion::linalg {

    template<typename T>
    concept TensorTypes = std::floating_point<T>;
    
    /*
      Tensor is the fundamental multidimensional data structure used by Axion.

      Internally, its storage is currently implemented as a
      std::vector<std::vector<T>>, providing a matrix-like layout while
      keeping the interface simple and intuitive for machine learning tasks.

      This design prioritizes usability and readability, allowing users to
      manipulate tensor data without dealing with unnecessarily complex
      notation or low-level memory management details.

      Only floating-point types are supported, as enforced by the
      TensorTypes concept.
    */
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
