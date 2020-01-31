


int
foo (int a[], int b[], int i)
{
  a[i] = b[i] + 2;
  i++;
  a[i] = b[i] + 2;
  i++;
  a[i] = b[i] + 2;
  i++;
  a[i] = b[i] + 2;
  i++;
  return i;
}
