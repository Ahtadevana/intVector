#include "intVec.h"
#include <stdio.h>
#include <stdlib.h>

// TODO: vector custom errors

int vecInit(Vec *vec, size_t initSize) {
  if (initSize == 0 || vec == NULL || vec->base != NULL)
    return -1;

  // TODO: resolve size_t under/overflow
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

// TODO: resolve size_t under/overflow
int vecReserve(Vec *vec, size_t newCap) {
  if (vec == NULL || vec->base == NULL)
    return -1;

  if (vec->cap == 0 || newCap < vec->cap)
    return -1;

  if (vec->cap == newCap)
    return 0;

  const size_t allocSize = newCap * sizeof(*vec->base);

  int *newBase = realloc(vec->base, allocSize);
  if (newBase == NULL)
    return -1;
  vec->base = newBase;

  vec->cap = newCap;
  return 0;
}

int vecPushBack(Vec *vec, int data) {
  if (vec == NULL)
    return -1;

  if (vec->base == NULL)
    if (vecInit(vec, 1) != 0)
      return -1;

  if (vec->size == vec->cap) {
    // TODO: resolve size_t under/overflow
    const size_t newCap = vec->cap * 2;
    const size_t allocSize = newCap * sizeof(*vec->base);

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

int vecPopBack(Vec *vec) {
  if (vec == NULL || vec->base == NULL || vec->size == 0)
    return -1;

  vec->size--;
  return 0;
}

void vecPrint(const Vec *vec) {
  if (vec == NULL) {
    printf("NULL\n");
    return;
  }

  if (vec->base == NULL) {
    printf("[]NULL\n");
    return;
  }

  printf("[ ");
  for (size_t i = 0; i < vec->size; ++i) {
    printf("%d ", vec->base[i]);
  }
  printf("]\n");
}
