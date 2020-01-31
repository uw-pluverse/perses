





typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void abort ();


int a[40];

__attribute__ ((noinline)) int
foo (int n){
  int i,j;
  int sum;

  if (n<=0)
    return 0;


  for (i = 0; i < 40; i++) {
    sum = 0;
    for (j = 0; j < n; j+=2) {
      sum += j;
    }
    a[i] = sum + j;
  }
}

int main (void)
{
  int i,j;
  int sum;

  for (i=0; i<40; i++)
    a[i] = i;

  foo (40);


  for (i=0; i<40; i++)
    {
      sum = 0;
      for (j = 0; j < 40; j+=2)
        sum += j;
      if (a[i] != sum + j)
        abort();
    }

  return 0;
}
