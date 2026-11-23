#ifndef INT_VECTOR_H
#define INT_VECTOR_H

#include <stddef.h>

typedef struct Vec {
  int *base;
  size_t size;
  size_t cap;
} Vec;

int vecInit(Vec *vec, size_t initSize);
void vecDestroy(Vec *vec);

int vecPushBack(Vec *vec, int data);
int vecPopBack(Vec *vec);

#endif // !INT_VECTOR_H
