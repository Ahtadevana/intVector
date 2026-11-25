#include "intVec.h"
#include <stdio.h>
#define LOG(X) printf("%zu, %zu\n", X.size, X.cap)

int main() {
  Vec v = {0};

  vecPushBack(&v, 10);
  LOG(v);

  vecPushBack(&v, 20);
  LOG(v);

  vecPushBack(&v, 30);
  LOG(v);

  vecDestroy(&v);
  return 0;
}
