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
			throw std::invalid_argument("Initializer size mismatch");
		}
	}

	std::size_t Matrix::index(std::size_t row, std::size_t col) const noexcept {
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
			throw std::invalid_argument("Dimension mismatch for addition");
		}

		Matrix result(rows_, cols_);

		for (std::size_t i = 0; i < data_.size(); ++i) {
			result.data_[i] = data_[i] + other.data_[i];
		}

		return result;
	}

	Matrix& Matrix::operator+=(const Matrix& other) {
		if (rows_ != other.rows_ ||
			cols_ != other.cols_) {
			throw std::invalid_argument("Dimension mismatch for +=");
		}

		for (std::size_t i = 0; i < data_.size(); ++i) {
			data_[i] += other.data_[i];
		}

		return *this;
	}

	Matrix Matrix::operator-(const Matrix& other) const {
		if (rows_ != other.rows_ ||
			cols_ != other.cols_) {
			throw std::invalid_argument("Dimension mismatch for subtraction");
		}

		Matrix result(rows_, cols_);

		for (std::size_t i = 0; i < data_.size(); ++i) {
			result.data_[i] = data_[i] - other.data_[i];
		}

		return result;
	}

	Matrix& Matrix::operator-=(const Matrix& other) {
		if (rows_ != other.rows_ ||
			cols_ != other.cols_) {
			throw std::invalid_argument("Dimension mismatch for -=");
		}

		for (std::size_t i = 0; i < data_.size(); ++i) {
			data_[i] -= other.data_[i];
		}

		return *this;
	}

	Matrix Matrix::operator+(double scalar) const {
		Matrix result(*this);

		for (double& v : result.data_) {
			v += scalar;
		}

		return result;
	}

	Matrix& Matrix::operator+=(double scalar) {
		for (double& v : data_) {
			v += scalar;
		}

		return *this;
	}

	Matrix Matrix::operator-(double scalar) const {
		Matrix result(*this);

		for (double& v : result.data_) {
			v -= scalar;
		}

		return result;
	}

	Matrix& Matrix::operator-=(double scalar) {
		for (double& v : data_) {
			v -= scalar;
		}

		return *this;
	}

	Matrix Matrix::operator*(double scalar) const {
		Matrix result(*this);

		for (double& v : result.data_) {
			v *= scalar;
		}

		return result;
	}

	Matrix& Matrix::operator*=(double scalar) {
		for (double& v : data_) {
			v *= scalar;
		}

		return *this;
	}

	Matrix Matrix::operator/(double scalar) const {
		if (scalar == 0.0) {
			throw std::invalid_argument("Division by zero");
		}

		Matrix result(*this);

		for (double& v : result.data_) {
			v /= scalar;
		}

		return result;
	}

	Matrix& Matrix::operator/=(double scalar) {
		if (scalar == 0.0) {
			throw std::invalid_argument("Division by zero");
		}

		for (double& v : data_) {
			v /= scalar;
		}

		return *this;
	}

	Matrix operator+(double scalar, const Matrix& m) {
		return m + scalar;
	}

	Matrix operator-(double scalar, const Matrix& m) {
		Matrix result(m.rows_, m.cols_);

		for (std::size_t i = 0; i < m.data_.size(); ++i) {
			result.data_[i] = scalar - m.data_[i];
		}

		return result;
	}

	Matrix operator*(double scalar, const Matrix& m) {
		return m * scalar;
	}

	Matrix Matrix::operator*(const Matrix& other) const {
		if (cols_ != other.rows_) {
			throw std::invalid_argument("Dimension mismatch for multiplication");
		}

		Matrix result(rows_, other.cols_);

		for (std::size_t i = 0; i < rows_; ++i) {
			for (std::size_t j = 0; j < other.cols_; ++j) {
				double sum = 0.0;

				for (std::size_t k = 0; k < cols_; ++k) {
					sum += data_[i * cols_ + k] *
						other.data_[k * other.cols_ + j];
				}

				result(i, j) = sum;
			}
		}

		return result;
	}

	Matrix Matrix::transpose() const noexcept {
		Matrix result(cols_, rows_);

		for (std::size_t i = 0; i < rows_; ++i) {
			for (std::size_t j = 0; j < cols_; ++j) {
				result(j, i) = (*this)(i, j);
			}
		}

		return result;
	}

    Matrix Matrix::hadamard(const Matrix& other) const {
        Matrix result(cols_, rows_);
        if (rows_ != other.rows_ ||
			cols_ != other.cols_) {
			throw std::invalid_argument("Dimension mismatch for -=");
		}
        
        for (std::size_t i = 0; i < rows_; ++i) {
            for (std::size_t j = 0; j < cols_; ++j) {
                result(i, j) = (*this)(i,j) * (other)(i,j);
            }
        }

        return result;
    }

	std::size_t Matrix::rows() const noexcept {
		return rows_;
	}

	std::size_t Matrix::cols() const noexcept {
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
