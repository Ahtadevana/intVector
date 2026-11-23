#include "intVec.h"
#include <stdlib.h>

// TODO: resolve size_t under/overflow
// TODO: vector custom errors

int vecInit(Vec *vec, size_t initSize) {
  if (initSize == 0 || vec == NULL || vec->base != NULL)
    return -1;

  vec->base = malloc(initSize * sizeof *(vec->base));
  if (vec->base == NULL)
    return -1;

  vec->cap = initSize;
  return 0;
}

void vecDestroy(Vec *vec) {
  if (vec == NULL)
    return;

  free(vec->base);
  vec->base = NULL;

  vec->size = 0;
  vec->cap = 0;
}

int vecPushBack(Vec *vec, int data) {
  if (vec == NULL)
    return -1;

  if (vec->base == NULL)
    if (vecInit(vec, 1) != 0)
      return -1;

  if (vec->size == vec->cap) {
    const size_t newCap = vec->cap * 2;
    const size_t allocSize = newCap * sizeof *vec->base;

    int *newBase = realloc(vec->base, allocSize);
    if (newBase == NULL)
      return -1;
    vec->base = newBase;
    vec->cap = newCap;
  }

  vec->base[vec->size] = data;
  vec->size++;
  return 0;
}
