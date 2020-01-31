


void abort(void);
int main()
{
  int a[2];
  int i = 1;
  a[0] = 1;
  a[1] = 2;
  if (*(a + i) != 2)
    abort();
  return 0;
}
