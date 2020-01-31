

int a[2];
int test2 (void);
void
test(int c)
{
  int i;
  for (i=0;i<c;i++)
    {
      a[i]=5;
      if (test2())
 return;
    }
}
