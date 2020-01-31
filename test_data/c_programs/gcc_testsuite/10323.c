


extern void abort (void);

int a;

int
main(void)
{
  if (a * 1000 < 0)
    abort ();
  if (a * -43 > 0)
    abort ();
  return 0;
}
