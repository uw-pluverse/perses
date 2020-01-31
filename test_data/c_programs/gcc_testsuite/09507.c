




extern int a[];

void
foo (void)
{
  __builtin_prefetch (a, 0, 0);
}
