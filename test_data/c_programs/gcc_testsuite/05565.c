

void foo(int *p, long i, int j)
{
  do {
      p[i]++;
  } while (i += j);
}
