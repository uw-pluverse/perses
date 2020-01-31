


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;




int A[16] = {36,39,42,45,43,32,21,12,23,34,45,56,67,78,89,11};

extern void abort(void);

int main1 ()
{
  int i, j;

  for (i = 0; i < 16; i++)
    {
      j = A[i];
      A[i] = ( j >= 42 ? 42 : 0);
    }


  for (i = 0; i < 16; i++)
    {
      if (A[i] > 42)
 abort ();
    }

  return 0;
}
