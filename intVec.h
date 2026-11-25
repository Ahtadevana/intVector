#ifndef INT_VECTOR_H
#define INT_VECTOR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Vec {
  int *base;
  size_t size;
  size_t cap;
} Vec;

int vecInit(Vec *vec, size_t initSize);
void vecDestroy(Vec *vec);

int vecReserve(Vec *vec, size_t newSize);
// TODO: vecshrink
int vecShrink(Vec *vec, size_t newCap);

int vecPushBack(Vec *vec, int data);
// TODO: insertAt, replaceByIndex
int vecInsertAt(Vec *vec, size_t index, int data);
int vecSet(Vec *vec, size_t index, int data);

int vecPopBack(Vec *vec);
// TODO: clear, popByIndex
int vecClear(Vec *vec);
int vecRemoveAt(Vec *vec, size_t index);

int vecGetAt(const Vec *vec, size_t index, int *result);

void vecPrint(const Vec *vec);

// TODO: emptyCheck
bool isEmpty(const Vec *vec);

#endif // !INT_VECTOR_H
