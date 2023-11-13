#include "gpu.hpp"
#include <iostream>
#include <vector>

int main() {

  std::size_t n = 128 * 100;
  auto vec_a = std::vector<float>(n, 5.0);
  auto vec_b = std::vector<float>(n, 3.0);
  auto res = gpu::sum_vector(vec_a, vec_b);

  std::cout << "result[0]: " << res[0] << std::endl;

  return 0;
}
