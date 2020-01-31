


struct
{
  struct
    {
      int a;
      int b;
    } a[100];
} a;

typedef long unsigned int size_t;
void foo(size_t);
size_t *bar (void);

int
main (void)
{
  size_t *b = bar ();


  foo (&a.a[50].a - &a.a[33].b);
  foo ((size_t) &a.a[50].b - (size_t) &a);


  foo ((size_t) &b - (size_t) b);
  return 0;
}
