#include "kernel.cuh"
#include <vector>

namespace gpu {

template <typename T>
std::vector<T> sum_vector(std::vector<T> &vec_a, std::vector<T> &vec_b) {
  std::vector<T> result(vec_a.size());
  wrap_sum_vector(vec_a.data(), vec_b.data(), result.data(), vec_a.size());

  return result;
}

} // namespace gpu
