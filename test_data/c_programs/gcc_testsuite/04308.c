
void
foo (void)
{
  long long int a;
  unsigned long b[249];
  register unsigned int c;
  b[c] = (a & (1ULL << c)) ? 1 : 0;
}
