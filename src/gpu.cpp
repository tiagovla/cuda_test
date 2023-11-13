#include "gpu.hpp"
#include "kernel.cuh"

std::vector<float> gpu::sum_vector(std::vector<float> &vec_a,
                                  std::vector<float> &vec_b) {
  std::vector<float> result(vec_a.size());
  wrap_sum_vector(vec_a.data(), vec_b.data(), result.data(), vec_a.size());

  return result;
}
