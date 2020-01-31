




void *foo(int i, int *p)
{
lab:
  if (p) *p = i;
  goto *p;
  return &&lab;
}
