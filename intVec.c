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
