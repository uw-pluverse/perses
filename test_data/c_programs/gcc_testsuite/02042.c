void f (long *limit, long *base, long minLen, long maxLen) __attribute__ ((__noinline__));
void f (long *limit, long *base, long minLen, long maxLen)
{
  long i;
  long vec;
  vec = 0;
  for (i = minLen; i <= maxLen; i++) {
    vec += (base[i+1] - base[i]);
    limit[i] = vec-1;
  }
}
extern void abort (void);
extern void exit (int);
long b[] = {1, 5, 11, 23};
int main (void)
{
  long l[3];
  f (l, b, 0, 2);
  if (l[0] != 3 || l[1] != 9 || l[2] != 21)
    abort ();
  exit (0);
}
