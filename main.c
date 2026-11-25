#include "intVec.h"
#include <stdio.h>
#define LOG(X) printf("%zu, %zu\n", X.size, X.cap)

int main() {
  Vec v;

  vecPrint(&v);

  return 0;
}
