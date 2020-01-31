





extern void abort (void);
extern void exit (int);

void foo (int x)
{
  if (x != 1)
    abort ();
}

int z;

int main (int argc, char **argv)
{
  char *a = "test";
  char *b = a + 2;

  foo (z > 0 ? b - a : b - a - 1);
  exit (0);
}
