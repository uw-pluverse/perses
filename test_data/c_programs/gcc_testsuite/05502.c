







extern void abort (void) __attribute__((noreturn));

int main (void)
{
  long a, i;

  for (i = 0; i < 5; i++)
    a = i * i;
  if (a != 16)
    abort ();
  return 0;
}
