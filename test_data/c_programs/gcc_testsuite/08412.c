

void abort (void);







int main (void)
{

  if (1 != 1)
    abort ();
  if (2 != 2)
    abort ();
  if (3 != 3)
    abort ();
  if (4 != 4)
    abort ();
  if (5 != 5)
    abort ();

  return 0;
}
