




typedef struct {
  unsigned char a;
} A;

unsigned int foo (A *x)
{
  unsigned char b[2] = { 0, 0 };
  unsigned char c = 0;

  c = (x->a) ? b[1] : b[0];

  return (unsigned int) c;
}
