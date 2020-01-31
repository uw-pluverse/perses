



void
foo1 (int n, int *a, int workgroup_size)
{
  int i;
 for (i = 0; i < n; i++)
      a[i]++;
}

void
foo2 (int j, int n, int *a)
{
  int i;
 for (i = j + 1; i < n; i++)
      a[i] = i;
}

void
foo3 (int j, int n, int *a)
{
  int i;
 for (i = j + 1; i < n; i += 3)
    a[i] = i;
}

void
foo4 (int j, int n, int *a)
{
 {
 {
      int i;
 for (i = j + 1; i < n; i += 3)
 a[i] = i;
    }
  }
}
