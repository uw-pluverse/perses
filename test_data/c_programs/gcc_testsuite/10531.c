







int foo (int a, int b)
{
  int c = (a && b) || 0;
  c = a && b || 0;

  return (a && b && 1) || 0;
}
