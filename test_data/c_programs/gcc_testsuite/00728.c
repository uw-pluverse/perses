

extern void abort (void);

int
test (int i, ...)
{
  float f = (float) i;
  if (f != f) abort ();
  return 2;
}
