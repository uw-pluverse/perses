



int p1[256], p2[256], p3[256];
int c[256];
void foo (int n)
{
  int i;
  for (i=0; i<n; i++)
    if (c[i])
      {
 p1[i] += 1;
 p2[i] = p3[i] +2;
      }
}
