







extern void abort(void);

long long smod16(long long x)
{
  return x % 16;
}

int main(void)
{

  if (smod16 (0xFFFFFFFF) != 0xF)
    abort ();


  return 0;
}
