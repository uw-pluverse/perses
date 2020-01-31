


int global_1, global_2;

__attribute__((__noclone__)) int g (int b, int c)
 {
  global_1 = b;
  global_2 = c;
}

__attribute__((__noclone__)) int f (int a)
{

  if (a > 0)
    g (a, 3);
  else
    g (a, 5);
}

int main ()
{
  f (7);
  return 0;
}
