#include "intVec.h"
#include <stdio.h>

int main() {
  Vec v = {0};

  if (vecPushBack(&v, 10) != 0)
    printf("Naw\n");

  vecDestroy(&v);
  return 0;
}
