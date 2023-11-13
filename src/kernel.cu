#include "kernel.cuh"

template <typename T> __global__ void sum_kernel(T *a, T *b, T *c, int n) {
  int id = blockDim.x * blockIdx.x + threadIdx.x;
  if (id < n)
    c[id] = a[id] + b[id];
}

template <typename T> void wrap_sum_vector(T *a, T *b, T *res, int n) {
  int threads_per_block = 128;
  int blocks_per_grid = ceil(float(n) / threads_per_block);

  float *d_a, *d_b, *d_c;
  cudaMalloc((void **)&d_a, n * sizeof(float));
  cudaMalloc((void **)&d_b, n * sizeof(float));
  cudaMalloc((void **)&d_c, n * sizeof(float));

  cudaMemcpy(d_a, a, n * sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, b, n * sizeof(float), cudaMemcpyHostToDevice);

  sum_kernel<<<blocks_per_grid, threads_per_block>>>(d_a, d_b, d_c, n);

  cudaMemcpy(res, d_c, n * sizeof(float), cudaMemcpyDeviceToHost);

  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);
}

template void wrap_sum_vector<int>(int *a, int *b, int *res, int n);
template void wrap_sum_vector<float>(float *a, float *b, float *res, int n);
template void wrap_sum_vector<double>(double *a, double *b, double *res, int n);
