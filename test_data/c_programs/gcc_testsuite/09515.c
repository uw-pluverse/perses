




int *v;

void
foo (int a)
{
  int i, j;
  for (j = i = a; i != -1; j = i, i = v[i])
    ;
  v[j] = v[a];
}
