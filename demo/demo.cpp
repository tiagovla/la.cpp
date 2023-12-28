#include "lacpp/matrix.hpp"
#include <iostream>

template <typename T>
std::ostream &operator<<(std::ostream &output, const lacpp::Matrix<T> &m) {
  for (int r = 0; r < m.rows(); r++) {
    output << "[";
    for (int c = 0; c < m.cols(); c++) {
      if (c != 0)
        output << ", ";
      output << m(r, c);
    }
    output << "]";
    output << std::endl;
  }
  return output;
}

int main() {
  std::size_t rows = 500, cols = 500;
  auto mat1 = lacpp::Matrix<float>::ones(rows, cols);
  auto mat2 = lacpp::Matrix<float>::ones(rows, cols);
  auto mat = mat1 * mat2;
  std::cout << mat << std::endl;
  std::cout << sizeof(mat) << std::endl;
  std::vector<float> vec;
  std::cout << sizeof(vec) << std::endl;
  std::cout << sizeof(lacpp::matrix_layout) << std::endl;


  return 0;
}
