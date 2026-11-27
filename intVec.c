#include "intVec.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// TODO: vector custom errors

int vec_init(Vec *vec, size_t init_size) {
  if (init_size == 0 || vec == NULL || vec->base != NULL)
    return -1;

  if (init_size > SIZE_MAX / sizeof *vec->base)
    return -1;

  vec->base = malloc(init_size * sizeof *vec->base);
  if (vec->base == NULL)
    return -1;

  vec->cap = init_size;
  return 0;
}

void vec_destroy(Vec *vec) {
  if (vec == NULL)
    return;

  free(vec->base);
  vec->base = NULL;

  vec->size = 0;
  vec->cap = 0;
}

int vec_reserve(Vec *vec, size_t new_cap) {
  if (vec == NULL)
    return -1;

  if (new_cap > SIZE_MAX / sizeof *vec->base)
    return -1;

  if (vec->base == NULL)
    if (vec_init(vec, new_cap) != 0)
      return -1;

  if (new_cap <= vec->cap)
    return 0;

  const size_t alloc_size = new_cap * sizeof *vec->base;

  int *new_base = realloc(vec->base, alloc_size);
  if (new_base == NULL)
    return -1;
  vec->base = new_base;

  vec->cap = new_cap;
  return 0;
}

int vec_shrink(Vec *vec, size_t new_cap) {
  if (vec == NULL || vec->base == NULL)
    return -1;

  if (new_cap > SIZE_MAX / sizeof *vec->base)
    return -1;

  if (new_cap >= vec->cap)
    return 0;

  size_t alloc_size = new_cap * sizeof *vec->base;

  int *new_base = realloc(vec->base, alloc_size);
  if (new_base == NULL)
    return -1;
  vec->base = new_base;

  vec->size = new_cap < vec->size ? new_cap : vec->size;
  vec->cap = new_cap;

  return 0;
}

int vec_pushback(Vec *vec, int data) {
  if (vec == NULL)
    return -1;

  if (vec->base == NULL)
    if (vec_init(vec, 1) != 0)
      return -1;

  if (vec->size == vec->cap) {
    const size_t new_cap = vec->cap * 2;

    if (new_cap > SIZE_MAX / sizeof *vec->base)
      return -1;

    const size_t alloc_size = new_cap * sizeof *vec->base;

    int *new_base = realloc(vec->base, alloc_size);
    if (new_base == NULL)
      return -1;
    vec->base = new_base;

    vec->cap = new_cap;
  }

  vec->base[vec->size] = data;
  vec->size++;
  return 0;
}

int vec_insert_at(Vec *vec, size_t index, int data) {
  if (vec == NULL || vec->base == NULL)
    return -1;

  if (index >= vec->size)
    return -1;

  if (vec->size == vec->cap) {
    const size_t new_cap = vec->cap * 2;
    if (new_cap > SIZE_MAX / sizeof *vec->base)
      return -1;

    const size_t alloc_size = new_cap * sizeof *vec->base;

    int *new_arr = malloc(alloc_size);
    if (new_arr == NULL)
      return -1;

    // TODO: fix shifting algorithm
    for (size_t i = 0; i < vec->size; ++i) {
      if (i == index) {
        new_arr[i] = data;
        continue;
      }

      new_arr[i] = vec->base[i];
    }
  }

  for (size_t i = 0; i < vec->size; ++i) {
  }

  return 0;
}

int vec_popback(Vec *vec) {
  if (vec == NULL || vec->base == NULL || vec->size == 0)
    return -1;

  vec->size--;
  return 0;
}

int vec_get_at(const Vec *vec, size_t index, int *result) {
  if (vec == NULL || vec->base == NULL)
    return -1;

  if (index >= vec->size)
    return -1;

  if (result == NULL)
    return -1;

  *result = vec->base[index];
  return 0;
}

void vec_print(const Vec *vec) {
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

bool is_empty(const Vec *vec) { return vec->size == 0; }
