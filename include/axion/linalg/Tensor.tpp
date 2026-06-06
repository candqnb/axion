namespace axion::linalg {

	template <AllowedNumeric T>
	std::size_t Tensor<T>::flatten_size(std::initializer_list<std::size_t> shape) const {
		std::size_t total = 1;

		for (auto d : shape) {
			total *= d;
		}

		return total;
	}

	template <AllowedNumeric T>
	Tensor<T>::Tensor()
		: shape_(),
		  data_() {}

	template <AllowedNumeric T>
	Tensor<T>::Tensor(std::initializer_list<std::size_t> shape)
		: shape_(shape),
		  data_(flatten_size(shape)) {}

	template <AllowedNumeric T>
	Tensor<T>::Tensor(std::initializer_list<std::size_t> shape, T value)
		: shape_(shape),
		  data_(flatten_size(shape), value) {}

	template <AllowedNumeric T>
	std::size_t Tensor<T>::rank() const noexcept {
		return shape_.size();
	}

	template <AllowedNumeric T>
	std::size_t Tensor<T>::size() const noexcept {
		return data_.size();
	}

	template <AllowedNumeric T>
	const std::vector<std::size_t>& Tensor<T>::shape() const noexcept {
		return shape_;
	}

	template <AllowedNumeric T>
	T& Tensor<T>::operator()(std::size_t index) {
		if (index >= data_.size()) {
			throw std::out_of_range("Tensor index out of range");
		}
		return data_[index];
	}

	template <AllowedNumeric T>
	const T& Tensor<T>::operator()(std::size_t index) const {
		if (index >= data_.size()) {
			throw std::out_of_range("Tensor index out of range");
		}
		return data_[index];
	}

	template <AllowedNumeric T>
	void Tensor<T>::print(std::ostream& os) const {
		os << "Tensor(shape=";

		for (std::size_t i = 0; i < shape_.size(); ++i) {
			os << shape_[i];
			if (i + 1 < shape_.size()) os << ",";
		}

		os << ", size=" << data_.size() << ")\n";

		for (const auto& v : data_) {
			os << v << " ";
		}

		os << "\n";
	}

}
