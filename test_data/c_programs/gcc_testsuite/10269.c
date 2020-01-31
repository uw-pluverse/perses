


extern void foo (int);
extern void bar (int, char *);
void
f (void)
{
  foo ("../gcc-seed-programs/gcc.dg/pr61861.c");
  foo ("../gcc-seed-programs/gcc.dg/pr61861.c");
  foo ("04:16:39");
  foo ("Jun 18 2016");
  foo ("Sat Jun 18 00:00:53 2016");
  bar (1, 25);
  bar (0, 1);

  foo ("../gcc-seed-programs/gcc.dg/pr61861.c");
  foo ("04:16:39");
  foo ("Jun 18 2016");
  bar (1, 31);

  foo ("foo");
  foo ("foo");
  foo ("foo");
  bar (1, 42);
}
