



int f;
int g;
unsigned int
foo (int b, int x)
{
  if (b)
    x = *(int *)&f;
  g = x;
  return *(unsigned int*)&f;
}
float
bar (int b, int x)
{
  if (b)
    x = *(int *)&f;
  g = x;
  return *(float *)&f;
}
