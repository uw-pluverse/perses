



extern void abort (void);
extern void bitmap_clear (int *);
extern void bar (int *);

void
oof ()
{
  int live_head;
  int * live = &live_head;

  if (live)
   bitmap_clear (live);
}

void
foo(int n)
{
  int *space = (int *)__builtin_alloca (n);

  if (space == 0)
    abort ();
  else
    bar (space);
}
