



int
main(void)
{
  int i;
  int result, array[1000];
  int lresult;


 for (i = 0; i < 1000; i++)
    result += array[i];


 for (i = 0; i < 1000; i++)
    result *= array[i];


 for (i = 0; i < 1000; i++)
    result = result > array[i] ? result : array[i];


 for (i = 0; i < 1000; i++)
    result = result < array[i] ? result : array[i];


 for (i = 0; i < 1000; i++)
    result &= array[i];


 for (i = 0; i < 1000; i++)
    result |= array[i];


 for (i = 0; i < 1000; i++)
    result ^= array[i];


 for (i = 0; i < 1000; i++)
    lresult = lresult && (result > array[i]);


 for (i = 0; i < 1000; i++)
    lresult = lresult || (result > array[i]);

  return 0;
}
