



char e[5];

extern struct S
{
  int a;
  char b;
} s;

int
foo (int *a, char *b, char *c)
{
  int d = __builtin_memcmp (&s.a, e, 4);

  return s.a;
}
