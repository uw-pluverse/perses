


int a[16*100];
int e;
void foo(void)
{
  int i;
  for(i = 0;i<16*100;i++)
    e += a[i];
}
