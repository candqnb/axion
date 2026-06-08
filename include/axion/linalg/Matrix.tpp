namespace axion::linalg {

    template<AllowedTypes T>
    Matrix<T>::Matrix()
        : rows_(0),
          cols_(0)
    {
    }

    template<AllowedTypes T>
    Matrix<T>::Matrix(std::size_t rows, std::size_t cols)
        : rows_(rows),
          cols_(cols),
          data_(rows * cols, T{})
    {
    }

    template<AllowedTypes T>
    Matrix<T>::Matrix(std::size_t rows, std::size_t cols, std::initializer_list<T> values)
        : rows_(rows),
          cols_(cols),
          data_(values)
    {
        if (values.size() != rows * cols) {
            throw std::invalid_argument("Initializer size mismatch");
        }
    }

    template<AllowedTypes T>
    std::size_t Matrix<T>::index(std::size_t row, std::size_t col) const noexcept
    {
        return row * cols_ + col;
    }

    template<AllowedTypes T>
    T& Matrix<T>::operator()(std::size_t row, std::size_t col)
    {
        return data_[index(row, col)];
    }

    template<AllowedTypes T>
    const T& Matrix<T>::operator()(std::size_t row, std::size_t col) const
    {
        return data_[index(row, col)];
    }

    template<AllowedTypes T>
    Matrix<T> Matrix<T>::operator+(const Matrix& other) const
    {
        if (rows_ != other.rows_ ||
            cols_ != other.cols_) {
            throw std::invalid_argument("Dimension mismatch for addition");
        }

        Matrix<T> result(rows_, cols_);

        for (std::size_t i = 0; i < data_.size(); ++i) {
            result.data_[i] =
                data_[i] + other.data_[i];
        }

        return result;
    }

    template<AllowedTypes T>
    Matrix<T>& Matrix<T>::operator+=(const Matrix& other)
    {
        if (rows_ != other.rows_ ||
            cols_ != other.cols_) {
            throw std::invalid_argument("Dimension mismatch for +=");
        }

        for (std::size_t i = 0; i < data_.size(); ++i) {
            data_[i] += other.data_[i];
        }

        return *this;
    }

    template<AllowedTypes T>
    Matrix<T> Matrix<T>::operator+(T scalar) const
    {
        Matrix<T> result(*this);

        for (auto& v : result.data_) {
            v += scalar;
        }

        return result;
    }

    template<AllowedTypes T>
    Matrix<T>& Matrix<T>::operator+=(T scalar)
    {
        for (auto& v : data_) {
            v += scalar;
        }

        return *this;
    }

    template<AllowedTypes T>
    Matrix<T> Matrix<T>::operator-(const Matrix& other) const
    {
        if (rows_ != other.rows_ ||
            cols_ != other.cols_) {
            throw std::invalid_argument("Dimension mismatch for subtraction");
        }

        Matrix<T> result(rows_, cols_);

        for (std::size_t i = 0; i < data_.size(); ++i) {
            result.data_[i] =
                data_[i] - other.data_[i];
        }

        return result;
    }

    template<AllowedTypes T>
    Matrix<T>& Matrix<T>::operator-=(const Matrix& other)
    {
        if (rows_ != other.rows_ ||
            cols_ != other.cols_) {
            throw std::invalid_argument("Dimension mismatch for -=");
        }

        for (std::size_t i = 0; i < data_.size(); ++i) {
            data_[i] -= other.data_[i];
        }

        return *this;
    }

    template<AllowedTypes T>
    Matrix<T> Matrix<T>::operator-(T scalar) const
    {
        Matrix<T> result(*this);

        for (auto& v : result.data_) {
            v -= scalar;
        }

        return result;
    }

    template<AllowedTypes T>
    Matrix<T>& Matrix<T>::operator-=(T scalar)
    {
        for (auto& v : data_) {
            v -= scalar;
        }

        return *this;
    }

    template<AllowedTypes T>
    Matrix<T> Matrix<T>::operator*(T scalar) const
    {
        Matrix<T> result(*this);

        for (auto& v : result.data_) {
            v *= scalar;
        }

        return result;
    }

    template<AllowedTypes T>
    Matrix<T>& Matrix<T>::operator*=(T scalar)
    {
        for (auto& v : data_) {
            v *= scalar;
        }

        return *this;
    }

    template<AllowedTypes T>
    Matrix<T> Matrix<T>::operator/(T scalar) const
    {
        if (scalar == T{}) {
            throw std::invalid_argument("Division by zero");
        }

        Matrix<T> result(*this);

        for (auto& v : result.data_) {
            v /= scalar;
        }

        return result;
    }

    template<AllowedTypes T>
    Matrix<T>& Matrix<T>::operator/=(T scalar)
    {
        if (scalar == T{}) {
            throw std::invalid_argument("Division by zero");
        }

        for (auto& v : data_) {
            v /= scalar;
        }

        return *this;
    }

    template<AllowedTypes T>
    Matrix<T> Matrix<T>::operator*(const Matrix& other) const
    {
        if (cols_ != other.rows_) {
            throw std::invalid_argument("Dimension mismatch for multiplication");
        }

        Matrix<T> result(rows_, other.cols_);

        for (std::size_t i = 0; i < rows_; ++i) {
            for (std::size_t j = 0; j < other.cols_; ++j) {
                T sum{};

                for (std::size_t k = 0; k < cols_; ++k) {
                    sum += (*this)(i, k) *
                        other(k, j);
                }

                result(i, j) = sum;
            }
        }

        return result;
    }

    template<AllowedTypes T>
    Matrix<T> Matrix<T>::transpose() const noexcept
    {
        Matrix<T> result(cols_, rows_);

        for (std::size_t i = 0; i < rows_; ++i) {
            for (std::size_t j = 0; j < cols_; ++j) {
                result(j, i) = (*this)(i, j);
            }
        }

        return result;
    }

    template<AllowedTypes T>
    Matrix<T> Matrix<T>::hadamard(const Matrix& other) const
    {
        if (rows_ != other.rows_ ||
            cols_ != other.cols_) {
            throw std::invalid_argument("Dimension mismatch for Hadamard product");
        }

        Matrix<T> result(rows_, cols_);

        for (std::size_t i = 0; i < data_.size(); ++i) {
            result.data_[i] =
                data_[i] * other.data_[i];
        }

        return result;
    }

    template<AllowedTypes T>
    std::size_t Matrix<T>::rows() const noexcept
    {
        return rows_;
    }

    template<AllowedTypes T>
    std::size_t Matrix<T>::cols() const noexcept
    {
        return cols_;
    }

    template<AllowedTypes T>
    Matrix<T> operator+(T scalar, const Matrix<T>& m)
    {
        return m + scalar;
    }

    template<AllowedTypes T>
    Matrix<T> operator-(T scalar, const Matrix<T>& m)
    {
        Matrix<T> result(m.rows_, m.cols_);

        for (std::size_t i = 0; i < m.data_.size(); ++i) {
            result.data_[i] =
                scalar - m.data_[i];
        }

        return result;
    }

    template<AllowedTypes T>
    Matrix<T> operator*(T scalar, const Matrix<T>& m)
    {
        return m * scalar;
    }

    template<AllowedTypes T>
    std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
    {
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
