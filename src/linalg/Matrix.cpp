#include "linalg/Matrix.hpp"

#include <stdexcept>

namespace axion::linalg {

Matrix::Matrix()
    : rows_(0),
      cols_(0) {}

Matrix::Matrix(std::size_t rows, std::size_t cols)
    : rows_(rows),
      cols_(cols),
      data_(rows * cols, 0.0) {}

Matrix::Matrix(std::size_t rows, std::size_t cols, std::initializer_list<double> values)
    : rows_(rows),
      cols_(cols),
      data_(values) {

    if (values.size() != rows * cols) {
        throw std::runtime_error(
            "Initializer list size does not match matrix dimensions");
    }
}

std::size_t Matrix::index(std::size_t row, std::size_t col) const {
    return row * cols_ + col;
}

double& Matrix::operator()(std::size_t row, std::size_t col) {
    return data_[index(row, col)];
}

const double& Matrix::operator()(std::size_t row, std::size_t col) const {
    return data_[index(row, col)];
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows_ != other.rows_ ||
        cols_ != other.cols_) {
        throw std::runtime_error(
            "Matrix dimensions must match for addition");
    }
    Matrix result(rows_, cols_);
    for (std::size_t i = 0; i < data_.size(); ++i) {
        result.data_[i] = data_[i] + other.data_[i];
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows_ != other.rows_ ||
        cols_ != other.cols_) {
        throw std::runtime_error(
            "Matrix dimensions must match for subtraction");
    }
    Matrix result(rows_, cols_);
    for (std::size_t i = 0; i < data_.size(); ++i) {
        result.data_[i] = data_[i] - other.data_[i];
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols_ != other.rows_) {
        throw std::runtime_error(
            "Invalid matrix dimensions for multiplication");
    }
    Matrix result(rows_, other.cols_);
    for (std::size_t i = 0; i < rows_; ++i) {
        for (std::size_t j = 0; j < other.cols_; ++j) {
            double sum = 0.0;
            for (std::size_t k = 0; k < cols_; ++k) {
                sum += (*this)(i, k) * other(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols_, rows_);
    for (std::size_t i = 0; i < rows_; ++i) {
        for (std::size_t j = 0; j < cols_; ++j) {
            result(j, i) = (*this)(i, j);
        }
    }
    return result;
}

std::size_t Matrix::rows() const {
    return rows_;
}

std::size_t Matrix::cols() const {
    return cols_;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (std::size_t i = 0; i < matrix.rows_; ++i) {
        for (std::size_t j = 0; j < matrix.cols_; ++j) {
            os << matrix(i, j);
            if (j + 1 < matrix.cols_) {
                os << ' ';
            }
        }
        if (i + 1 < matrix.rows_) {
            os << '\n';
        }
    }
    return os;
}

}
