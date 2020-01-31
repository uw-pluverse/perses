extern void abort(void);

int main ()
{
  int darisa[4] __attribute__((aligned(16))) ;
  int *stephanie = (int *) darisa;

  if ((unsigned long) stephanie % 16 != 0)
    abort ();

  return 0;
}
