



extern __thread int t;

void
foo (int a)
{
  t = a;
}
