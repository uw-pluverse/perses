


unsigned int a, b, c, d;
extern int printf (const char *, ...);
int main(void)
{
  unsigned int e;
  unsigned int f;

  e = a + b;
  e = e + c;
  f = c + a;
  f = f + b;
  printf ("%d %d\n", e, f);
}
