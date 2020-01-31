




typedef struct S { int i; } *T;


void
foo (void *p)
{
  ((T) (p))->i++;
}
