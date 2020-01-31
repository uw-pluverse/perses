


typedef struct { int i; int j; } A;
int foo(A *a, int i)
{
  a->i = i;
  return a->i;
}
