




int main (void)
{
  int i;
  int x[1000];

  for (i = 0; i < 101; i++)
    x[i] = x[i+100];

  return x[12];
}
