






extern char a[];



void foo (unsigned int i_width, char* dst)
{
  unsigned long long i = 0;
  unsigned long long j = 0;
  for ( ; j < i_width; )
    {
      *dst = a[i];
      dst++;
      i += 2;
      j += 1;
    }
}
