#include "gpu.hpp"
#include <chrono>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename T>
std::vector<T> sum_vector(std::vector<T> &a, std::vector<T> &b) {
  std::vector<T> result(a.size());
  for (std::size_t i = 0; i < a.size(); ++i)
    result[i] = a[i] + b[i];
  return result;
}

template <typename T>
void time_it(std::string tag, T &a, T &b, T (*func)(T &, T &)) {
  auto start = std::chrono::high_resolution_clock::now();
  auto res = func(a, b);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << tag << " Elapsed Time: " << duration.count()
            << "(ms) Result[0]: " << res[0]
            << "(ms) Result[-1]: " << res[res.size() - 1] << std::endl;
}

int main() {
  std::size_t n = 1 << 30 >> 1; // 6GB
  auto vec_a = std::vector<float>(n, 5);
  auto vec_b = std::vector<float>(n, 3);

  time_it("GPU", vec_a, vec_b, gpu::sum_vector);
  time_it("CPU", vec_a, vec_b, sum_vector);

  return 0;
}
