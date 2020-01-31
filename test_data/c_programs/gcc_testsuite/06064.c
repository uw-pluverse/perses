


void foo (int b)
{
  void *p;
lab:
  if (b)
    p = &&lab;
  else
    {
lab2:
      p = &&lab2;
    }
  *(char *)p = 1;
}
