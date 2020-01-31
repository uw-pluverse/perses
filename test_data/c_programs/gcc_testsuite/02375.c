




long long mpy_res;

unsigned long long mpy (long a, long b)
{
  return (unsigned long long) a * (unsigned long long) b;
}

int main(void)
{
  mpy_res = mpy(1,-1);
  if (mpy_res != -1LL)
    abort ();
  return 0;
}
