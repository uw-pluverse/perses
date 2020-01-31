void bar ();

int toto (int i, int b)
{
  int j;
  int a[100];

  for (j = 0; j <= 20; j++)
    a[j] = b + i;

  if (a[12] == 23)
    b = 3;
  else
    b = 1;

  for (j = 0; j <= 20; j++)
    a[j] = b + i;

  return a[b];
}
