int *a;

int main()
{
  double d[6];
  int i, j;

  for (i=0; i<4; ++i)
    for (j=0; j<3; ++j)
      d[i+j] = 0;

  a = &i;

  return 0;
}
