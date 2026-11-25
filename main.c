#include "intVec.h"
#include <stdio.h>
#define LOG(X) printf("%zu, %zu\n", X.size, X.cap)

int main() {
  Vec v = {0};

  vecPushBack(&v, 10);
  vecPushBack(&v, 20);
  vecPushBack(&v, 30);
  vecPushBack(&v, 40);
  vecPushBack(&v, 50);
  vecPrint(&v);
  LOG(v);

  vecShrink(&v, 3);
  vecPrint(&v);
  LOG(v);

  vecDestroy(&v);

  return 0;
}
