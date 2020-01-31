
int bar;

void
foo (float a, volatile int * b)
{
  if (a < 0.1)
    bar = *b;
}
