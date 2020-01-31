





struct S { int s1; void *s2; };
struct T { struct S t1; unsigned long long t2; };
struct S *foo (unsigned long long);

struct S *
bar (struct S *x)
{
  return foo (((struct T *) x)->t2);
}
