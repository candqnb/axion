#pragma once

#include <concepts>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace axion::linalg {

    template<typename T>
    concept MatrixTypes = std::floating_point<T>;

    template<MatrixTypes T>
    class Matrix;

    template<MatrixTypes T>
    Matrix<T> operator+(T scalar, const Matrix<T>& m);

    template<MatrixTypes T>
    Matrix<T> operator-(T scalar, const Matrix<T>& m);

    template<MatrixTypes T>
    Matrix<T> operator*(T scalar, const Matrix<T>& m);

    template<MatrixTypes T>
    std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);

    /*
      Represents a dense matrix used throughout the Axion linear algebra module.

      The matrix data is stored internally in a contiguous std::vector<T>,
      using a row-major layout. Element access is performed through an
      index mapping function that converts two-dimensional coordinates
      into a one-dimensional storage position.

      Only floating-point types are supported, as enforced by the
      MatrixTypes concept.
    */
    template<MatrixTypes T>
    class Matrix {
    public:
        Matrix();
        Matrix(std::size_t rows, std::size_t cols);
        Matrix(std::size_t rows, std::size_t cols, std::initializer_list<T> values);

        T& operator()(std::size_t row, std::size_t col);
        const T& operator()(std::size_t row, std::size_t col) const;

        Matrix operator+(const Matrix& other) const;
        Matrix operator+(T scalar) const;

        Matrix& operator+=(const Matrix& other);
        Matrix& operator+=(T scalar);

        Matrix operator-(const Matrix& other) const;
        Matrix operator-(T scalar) const;

        Matrix& operator-=(const Matrix& other);
        Matrix& operator-=(T scalar);

        Matrix operator*(const Matrix& other) const;
        Matrix operator*(T scalar) const;

        Matrix& operator*=(T scalar);

        Matrix operator/(T scalar) const;
        Matrix& operator/=(T scalar);

        Matrix transpose() const noexcept;
        Matrix hadamard(const Matrix& other) const;

        std::size_t rows() const noexcept;
        std::size_t cols() const noexcept;

        friend Matrix<T> operator+<T>(T scalar, const Matrix<T>& m);
        friend Matrix<T> operator-<T>(T scalar, const Matrix<T>& m);
        friend Matrix<T> operator*<T>(T scalar, const Matrix<T>& m);

        friend std::ostream& operator<< <T>(std::ostream& os, const Matrix<T>& matrix);

    private:
        std::size_t rows_{};
        std::size_t cols_{};
        std::vector<T> data_;

        std::size_t index(std::size_t row, std::size_t col) const noexcept;
    };

}

#include "Matrix.tpp"
