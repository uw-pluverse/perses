



int foo()
{
  int i;
  *(long*)&i = 0;
  return i;
}
