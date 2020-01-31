




int dummy (int a);

char a;
short b;

void mmm (void)
{
  char dyn[dummy (3)];
  a = (char)&dyn[0];
  b = (short)&dyn[0];
}
