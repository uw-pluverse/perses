



int
main(void)
{
  int i;
  __complex__ double result, array[1000];
  int lresult;


 for (i = 0; i < 1000; i++)
    result += array[i];


 for (i = 0; i < 1000; i++)
    result *= array[i];


 for (i = 0; i < 1000; i++)
    lresult = lresult && (__real__(result) > __real__(array[i]));


 for (i = 0; i < 1000; i++)
    lresult = lresult || (__real__(result) > __real__(array[i]));

  return 0;
}
