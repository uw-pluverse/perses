


int a[256];
int *b, *c;
void foo (int i, int j)
{
  b = &a[i+j];
  c = &a[i+j];
}
