#include "kernel.cuh"
#include "math.h"

__global__ void sum_kernel(float *a, float *b, float *c, int n) {
  int id = blockDim.x * blockIdx.x + threadIdx.x;
  if (id < n)
    c[id] = a[id] + b[id];
}

void wrap_sum_vector(float *a, float *b, float *res, int n) {
  int threads_per_block = 256;
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
