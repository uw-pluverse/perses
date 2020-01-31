

int
t(int a)
{
 if (a)
  return t(a-1);
 else
  return 0;
}
