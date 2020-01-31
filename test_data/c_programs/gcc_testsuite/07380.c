



int ii[31];
char cc[31] =
  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };

void __attribute__((noinline,noclone))
foo (int s)
{
  int i;
  for (i = 0; i < s; i++)
    ii[i] = (int) cc[i];
}

int main (int argc, const char **argv)
{
  int i;
  foo (31);
  for (i = 0; i < 31; i++)
    if (ii[i] != i)
      __builtin_abort ();
}
