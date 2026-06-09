namespace axion::linalg {

    template<TensorTypes T>
    Tensor<T>::Tensor()
        : rows_(0),
          cols_(0)
    {
    }

    template<TensorTypes T>
    Tensor<T>::Tensor(std::size_t rows, std::size_t cols)
        : rows_(rows),
          cols_(cols)
    {
    }

    template<TensorTypes T>
    Tensor<T>::Tensor(std::size_t rows, std::size_t cols, std::vector<std::vector<T>> values)
        : rows_(rows),
          cols_(cols)
    {
        if (values.size() != rows) {
            throw std::invalid_argument("Row count mismatch");
        }
        data_ = values;
    }

}
