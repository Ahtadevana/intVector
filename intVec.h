#ifndef INT_VECTOR_H
#define INT_VECTOR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Vec {
  int *base;
  size_t size;
  size_t cap;
} Vec;

int vec_init(Vec *vec, size_t initSize);
void vec_destroy(Vec *vec);

int vec_reserve(Vec *vec, size_t newSize);
// TODO: vecshrink
int vec_shrink(Vec *vec, size_t newCap);

int vec_pushback(Vec *vec, int data);
// TODO: insertAt, replaceByIndex
int vec_insert_at(Vec *vec, size_t index, int data);
int vec_set(Vec *vec, size_t index, int data);

int vec_popback(Vec *vec);
// TODO: clear, popByIndex
int vec_clear(Vec *vec);
int vec_remove_at(Vec *vec, size_t index);

int vec_get_at(const Vec *vec, size_t index, int *result);

void vec_print(const Vec *vec);

bool is_empty(const Vec *vec);

#endif // !INT_VECTOR_H
