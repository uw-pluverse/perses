


typedef enum E { A = -1 } e;
int
foo (void)
{
  e e = A;
  return e + 1;
}
