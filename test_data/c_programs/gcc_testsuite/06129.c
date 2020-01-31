






long foo(long* p, long* p2, int N1, int N2)
{
  unsigned long i = 0;
  long* p_limit2 = p2 + N2;
  long s = 0;
  while (i < N1)
    {
      p2++;
      i += 16;
      if (p2 > p_limit2)
        break;
     s += p[i];
  }
  return s;
}
