# Axion

Axion is a machine learning framework designed to be simple and fast.

---

# Roadmap

## Phase 1 — Linear Algebra

### Matrix

- [x] Matrix construction
- [x] Matrix indexing
- [x] Matrix addition/subtraction
- [x] Scalar operations
- [x] Matrix multiplication
- [x] Transpose

### Next Steps

- [ ] Add Hadamard product (https://en.wikipedia.org/wiki/Hadamard_product_(matrices))
- [ ] Add `apply(function)` (https://en.cppreference.com/w/cpp/algorithm/transform)
- [ ] Add random initialization (https://en.cppreference.com/w/cpp/numeric/random)
- [ ] Add filled matrix helper (https://numpy.org/doc/stable/reference/generated/numpy.full.html)
- [ ] Add `sum()` (https://en.cppreference.com/w/cpp/algorithm/accumulate)
- [ ] Add `same_shape()` (https://numpy.org/doc/stable/user/basics.broadcasting.html)

---

## Phase 2 — Activation Functions

### `activation/Activation.hpp`

- [ ] Implement `sigmoid(x)`
- [ ] Implement `sigmoid_derivative(x)`

### Optional

- [ ] Implement `relu(x)`
- [ ] Implement `relu_derivative(x)`

---

## Phase 3 — Loss Functions

### `loss/Loss.hpp`

- [ ] Implement `mse(y_true, y_pred)`
- [ ] Implement `mse_derivative(...)`

---

## Phase 4 — Perceptron

### `nn/Perceptron`

#### Fields

- [ ] Weights
- [ ] Bias
- [ ] Learning rate

#### Methods

- [ ] `forward(input)`
- [ ] `predict(input)`
- [ ] `train(input, target)`

---

## Phase 5 — Dataset Utilities

### `data/Sample.hpp`

- [ ] Implement sample structure

```cpp
struct Sample {
    Matrix input;
    double target;
};
```

---

## Phase 6 — Dense Layer

### `nn/Dense`

#### Fields

- [ ] Weights
- [ ] Bias

#### Methods

- [ ] `forward(input)`

---

# Future Goals

- [ ] Backpropagation
- [ ] Multi-layer neural networks
- [ ] Optimizers
- [ ] Serialization
- [ ] SIMD optimizations
- [ ] GPU support
- [ ] Automatic differentiation
- [ ] CNNs/RNNs