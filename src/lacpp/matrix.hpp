#pragma once

#include <vector>

namespace lacpp {
enum class matrix_layout { row_major, colum_major };

template <typename T, matrix_layout Layout = matrix_layout::row_major>
class Matrix {
public:
  Matrix(std::size_t rows, std::size_t cols) : m_rows(rows), m_cols(cols) {
    storage = std::vector<T>(rows * cols);
    storage.reserve(rows * cols);
  }

  T &operator()(std::size_t i, std::size_t j) {
    if constexpr (Layout == matrix_layout::row_major) {
      return this->storage[i * this->m_cols + j];
    } else {
      return this->storage[j * this->m_rows + i];
    }
  }

  T operator()(std::size_t i, std::size_t j) const {
    if constexpr (Layout == matrix_layout::row_major) {
      return this->storage[i * this->m_cols + j];
    } else {
      return this->storage[j * this->m_rows + i];
    }
  }

  T &operator()(std::size_t i) { return this->storage[i]; }

  T operator()(std::size_t i) const { return this->storage[i]; }

  static Matrix zeros(std::size_t rows, std::size_t cols) {
    Matrix<T> result(rows, cols);
    std::fill(result.storage.begin(), result.storage.end(), 0);
    return result;
  }

  static Matrix ones(std::size_t rows, std::size_t cols) {
    Matrix<T> result(rows, cols);
    std::fill(result.storage.begin(), result.storage.end(), 1);
    return result;
  }

  Matrix operator+(const Matrix &rhs) const {
    Matrix<T> result(m_rows, m_cols);
    for (std::size_t row = 0; row < m_rows; ++row)
      for (std::size_t col = 0; col < m_cols; ++col) {
        result(row, col) = (*this)(row, col) + rhs(row, col);
      }
    return result;
  }

  Matrix operator*(const Matrix &rhs) const {
    Matrix result(m_rows, rhs.m_cols);
    for (std::size_t i = 0; i < m_rows; ++i) {
      for (std::size_t k = 0; k < m_cols; ++k) {
        for (std::size_t j = 0; j < rhs.m_cols; ++j) {
          result(i, j) += (*this)(i, k) * rhs(k, j);
        }
      }
    }
    return result;
  }

  inline std::size_t size() const { return m_rows * m_cols; }

  inline std::size_t rows() const { return m_rows; }

  inline std::size_t cols() const { return m_cols; }

private:
  std::size_t m_rows, m_cols;
  matrix_layout layout;
  std::vector<T> storage;
};

} // namespace lacpp
