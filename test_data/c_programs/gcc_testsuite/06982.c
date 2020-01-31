


extern void abort (void);
int foo (int i, int j, int o, int m) { return i*o + 1 + j*m > 1; }
int main()
{
  if (foo (- 2147483647 - 1, -1, 1, 1))
    abort ();
  return 0;
}
