


extern void abort (void);



int main(void)
{
  long long Y, Y2;

  int U1;



  unsigned int t;

  U1 = -2147483647-1;

  Y = ((long long)(int)((unsigned int)((int)((long long)U1 * (long long)3) + 2) * (unsigned int)((int)((long long)U1 * (long long)3) + 2)) * 3);

  t = (unsigned int)((int)((long long)U1 * (long long)3) + 2);
  Y2 = ((long long)(int)(t * t) * 3);

  if (Y != Y2)
    abort ();
  return 0;
}
