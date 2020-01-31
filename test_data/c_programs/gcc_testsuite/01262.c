




void f()
{
  for (;;);
}

volatile int g;
void f2(int i)
{
  if (i) g=0;
}

void f3(int i)
{
  if (i) {
    g=0;
    g=1;
    g=2;
    g=3;
    g=4;
    g=5;
    g=6;
    g=7;
    g=8;
    g=9;
  }
}
