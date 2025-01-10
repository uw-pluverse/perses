



void bar (int, void (*) (void));

__attribute__((target_clones ("default", "avx")))
void foo (void)
{
  bar (0, foo);
  bar (0, foo);
}

__attribute__((target_clones ("default", "avx", "avx2")))
void baz (void)
{
  bar (0, foo);
  bar (0, foo);
  bar (0, foo);
  bar (0, foo);
  bar (0, foo);
  bar (0, foo);
}
