

int a[8];
int t()
{
 int i;
 for (i = 0; i < 3; i++)
  if (a[i])
   break;
 return i;
}
