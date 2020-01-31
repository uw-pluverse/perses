




extern void bar (int);

void foo ()
{
  int a = (-2147483647 -1);
  int b = -1;
  bar (a / b);
  bar (a % b);
}
