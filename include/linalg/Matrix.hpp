#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <vector>

namespace axion::linalg {

	class Matrix {
	public:
		Matrix();
		Matrix(std::size_t rows, std::size_t cols);
		Matrix(std::size_t rows, std::size_t cols, std::initializer_list<double> values);

		double& operator()(std::size_t row, std::size_t col);
		const double& operator()(std::size_t row, std::size_t col) const;

		Matrix operator+(const Matrix& other) const;
		Matrix operator+(double scalar) const;
		friend Matrix operator+(double scalar, const Matrix& m);

		Matrix& operator+=(const Matrix& other);
		Matrix& operator+=(double scalar);

		Matrix operator-(const Matrix& other) const;
		Matrix operator-(double scalar) const;
		friend Matrix operator-(double scalar, const Matrix& m);

		Matrix& operator-=(const Matrix& other);
		Matrix& operator-=(double scalar);

		Matrix operator*(const Matrix& other) const;
		Matrix operator*(double scalar) const;
		friend Matrix operator*(double scalar, const Matrix& m);

		Matrix& operator*=(double scalar);

		Matrix operator/(double scalar) const;
		Matrix& operator/=(double scalar);

		Matrix transpose() const noexcept;

		std::size_t rows() const noexcept;
		std::size_t cols() const noexcept;

		friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

	private:
		std::size_t rows_;
		std::size_t cols_;
		std::vector<double> data_;

		std::size_t index(std::size_t row, std::size_t col) const noexcept;
	};

}
