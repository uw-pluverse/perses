





void
f0 (int a[restrict])
{
  int **b = &a;
  int *restrict *c = &a;
}

void
f1 (a)
     int a[restrict];
{
  int **b = &a;
  int *restrict *c = &a;
}
