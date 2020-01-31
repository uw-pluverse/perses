





__attribute__((__vector_size__(4*sizeof(int)) )) signed int v1[]={0,1,2,3,4,5,6,7};


int main(void)
{
  int i;
  for (i = 0; i < sizeof(v1)/sizeof(v1[0]); i++)
  {
    __attribute__((__vector_size__(4*sizeof(int)) )) int t = v1[i];
    int *d = (int*)&t;
    int j;
    for (j = 0; j < 4; j++)
      {
        if (d[j] != i * 4 + j)
   __builtin_abort ();
      }
  }
  return 0;
}
