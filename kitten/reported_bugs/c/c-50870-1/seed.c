





#include <stdlib.h>
#include "lob.h"

int a[N];
int b[N];
int c[N];

static __attribute__ ((always_inline)) inline int
foo (int a, int b)
{
  NO_LOB;
  return a + b;
}

int
main (void)
{
  for (int i = 0; i < N; i++)
    {
      a[i] = i;
      b[i] = i * 2;
      c[i] = foo(a[i], b[i]);
    }

  return 0;
}
