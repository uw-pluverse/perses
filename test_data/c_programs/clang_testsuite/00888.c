typedef struct { char x[3]; } A0;
void foo (int i, ...);
int main (void)
{
  A0 a3;
  a3.x[0] = 0;
  a3.x[0] = 0;
  a3.x[2] = 26;
  foo (1, a3 );
  return 0;
}
