#include "gpu.hpp"
#include <iostream>
#include <vector>

int main() {

  std::size_t n = 128 * 100;
  std::vector<float> vec_a(n, 5);
  std::vector<float> vec_b(n, 3);

  std::vector<float> res = GPU_sum_vector(vec_a, vec_b);

  std::cout << "result[0]: " << res[0] << std::endl;

  return 0;
}
