


extern void abort (void);
unsigned long
foo (long i, long j)
{

  return -(unsigned long)(i * -j);
}
int main()
{
  if (foo (-9223372036854775807L - 1, -1) != -(unsigned long)(-9223372036854775807L - 1))
    abort ();
  return 0;
}
