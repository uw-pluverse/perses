




int
main ()
{
  int arr[128], i, s = 0;
  for (i = 0; i < 128; i++)
    arr[i] = i;

  for (i = 0; i < 128; i++)
    if (arr[i] != i)
      __builtin_abort ();

  for (i = 0; i < 128; i++)
    s += arr[i];
  if (s != (128 * (128 - 1)) / 2)
    __builtin_abort ();
  return 0;
}
