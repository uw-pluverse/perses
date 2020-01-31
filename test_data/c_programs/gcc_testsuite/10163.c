

int db[100];
int a_global_var, fact;
int main()
{
  int i,j=0;
  do
    {
      for (i=0; i<100; ++i)
        db[i] = i;
      fact = a_global_var * i;
    }
  while (j++ < 100);
}
