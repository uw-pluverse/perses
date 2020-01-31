

float a, b, c, d;
extern int printf (const char *, ...);
int main(void)
{
  float e;
  float f;

  e = a + b;
  e = e + c;
  f = c + a;
  f = f + b;
  printf ("%f %f\n", e, f);
}
