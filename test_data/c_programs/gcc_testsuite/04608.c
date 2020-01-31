





struct S { int a[16]; };

__attribute__((no_sanitize_undefined)) long long
foo (int *a, long long *b, struct S *c)
{
  return a[1] + *b + c->a[a[0]];
}
