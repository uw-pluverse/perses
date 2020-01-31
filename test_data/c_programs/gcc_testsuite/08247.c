


extern void abort (void);

int ifelse_val2;

int __attribute__((noinline))
test_ifelse2 (int i)
{
  int result = 0;
  if (!i)
    result = 1;
  if (i == 1)
    result = 1024;
  if (i == 2)
    result = 2;
  if (i == 3)
    return 8;
  if (i == 4)
    return 2048;
  return result;
}

void __attribute__((noinline))
call_ifelse ()
{
  ifelse_val2 += test_ifelse2 (0);
  ifelse_val2 += test_ifelse2 (2);
  ifelse_val2 += test_ifelse2 (2);
  ifelse_val2 += test_ifelse2 (2);
  ifelse_val2 += test_ifelse2 (3);
  ifelse_val2 += test_ifelse2 (3);
}

int
main()
{
  call_ifelse ();
  if (ifelse_val2 != 23)
    abort ();
  return 0;
}
