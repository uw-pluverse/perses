



int a;
const unsigned long long b[1] = { 1ULL };
extern void bar (int);

void
foo (void)
{
  for (a = 0; a == 1; a = 2)
    ;
  bar (b[0] == (a == 0 ? a : a / 0));
}
