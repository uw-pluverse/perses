




extern long long madd (long long a, long long b);

long long
foo ()
{
  return madd (0x0000000100000001LL, 0x0000011100000001LL);
}
