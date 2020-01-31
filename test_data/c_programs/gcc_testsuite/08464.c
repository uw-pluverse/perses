




extern void abort ();
extern void exit (int);

int main ()
{
  char *c, *d;

  c="a"; d="b";;
  if (c[0] != 'p' || d[0] != 'q')
    abort ();

  exit (0);
}
