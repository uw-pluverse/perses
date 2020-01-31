


int a;
void fn1()
{
  int k = 0;
  for (; k < 6;)
    for (a = 0; a < 6; k++)
      a = k + 6;
}
