typedef __typeof__(sizeof(int)) size_t;
extern void * malloc(size_t);
void * f1(int n)
{
  return malloc(n * sizeof(int));
}
void * f2(int n)
{
  return malloc(sizeof(int) * n);
}
void * f3()
{
  return malloc(4 * sizeof(int));
}
struct s4
{
  int n;
};
void * f4(struct s4 *s)
{
  return malloc(s->n * sizeof(int));
}
void * f5(struct s4 *s)
{
  struct s4 s2 = *s;
  return malloc(s2.n * sizeof(int));
}
void * f6(int n)
{
  return malloc((n + 1) * sizeof(int));
}
extern void * malloc (size_t);
void * f7(int n)
{
  if (n > 10)
    return ((void *) 0);
  return malloc(n * sizeof(int));
}
void * f8(int n)
{
  if (n < 10)
    return malloc(n * sizeof(int));
  else
    return ((void *) 0);
}
void * f9(int n)
{
  int * x = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    x[i] = i;
  return x;
}
void * f10(int n)
{
  int * x = malloc(n * sizeof(int));
  int i = 0;
  while (i < n)
    x[i++] = 0;
  return x;
}
void * f11(int n)
{
  int * x = malloc(n * sizeof(int));
  int i = 0;
  do {
    x[i++] = 0;
  } while (i < n);
  return x;
}
void * f12(int n)
{
  n = (n > 10 ? 10 : n);
  int * x = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    x[i] = i;
  return x;
}
struct s13
{
  int n;
};
void * f13(struct s13 *s)
{
  if (s->n > 10)
    return ((void *) 0);
  return malloc(s->n * sizeof(int));
}
void * f14(int n)
{
  if (n < 0)
    return ((void *) 0);
  return malloc(n * sizeof(int));
}
