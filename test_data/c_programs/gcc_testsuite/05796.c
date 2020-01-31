

int a[100];
void foo(int);
int
main()
{
  int i;
  for (i=0;i<100;i++)
    {
      if (a[i])
 continue;
       foo(i);
    }
}
