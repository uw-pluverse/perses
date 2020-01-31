
int __attribute__((noinline)) nge(int a, int b) {return -(a >= b);}
int __attribute__((noinline)) ngt(int a, int b) {return -(a > b);}
int __attribute__((noinline)) nle(int a, int b) {return -(a <= b);}
int __attribute__((noinline)) nlt(int a, int b) {return -(a < b);}
int __attribute__((noinline)) neq(int a, int b) {return -(a == b);}
int __attribute__((noinline)) nne(int a, int b) {return -(a != b);}
int __attribute__((noinline)) ngeu(unsigned a, unsigned b) {return -(a >= b);}
int __attribute__((noinline)) ngtu(unsigned a, unsigned b) {return -(a > b);}
int __attribute__((noinline)) nleu(unsigned a, unsigned b) {return -(a <= b);}
int __attribute__((noinline)) nltu(unsigned a, unsigned b) {return -(a < b);}


int main()
{
  if (nge((-2147483647 -1), 2147483647) != 0) abort();
  if (nge(2147483647, (-2147483647 -1)) != -1) abort();
  if (ngt((-2147483647 -1), 2147483647) != 0) abort();
  if (ngt(2147483647, (-2147483647 -1)) != -1) abort();
  if (nle((-2147483647 -1), 2147483647) != -1) abort();
  if (nle(2147483647, (-2147483647 -1)) != 0) abort();
  if (nlt((-2147483647 -1), 2147483647) != -1) abort();
  if (nlt(2147483647, (-2147483647 -1)) != 0) abort();

  if (neq((-2147483647 -1), 2147483647) != 0) abort();
  if (neq(2147483647, (-2147483647 -1)) != 0) abort();
  if (nne((-2147483647 -1), 2147483647) != -1) abort();
  if (nne(2147483647, (-2147483647 -1)) != -1) abort();

  if (ngeu(0, ~0U) != 0) abort();
  if (ngeu(~0U, 0) != -1) abort();
  if (ngtu(0, ~0U) != 0) abort();
  if (ngtu(~0U, 0) != -1) abort();
  if (nleu(0, ~0U) != -1) abort();
  if (nleu(~0U, 0) != 0) abort();
  if (nltu(0, ~0U) != -1) abort();
  if (nltu(~0U, 0) != 0) abort();

  exit(0);
}
