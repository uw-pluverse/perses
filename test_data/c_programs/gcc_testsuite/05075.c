


extern void abort (void);
extern int blah[];

void
foo(int index)
{
  if (blah [(unsigned int)index] != 0)
    abort ();
  if (blah [(unsigned int)index] != 0)
    abort ();
}
