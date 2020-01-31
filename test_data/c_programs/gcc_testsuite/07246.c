extern void abort (void);
extern void exit (int);

extern void recurser_void (int);
extern void track (int);

int main ()
{
  recurser_void (0);
  exit (0);
}

void
recurser_void (int n)
{
  if (n == 0 || n == 7)
    track (n);

  if (n == 10)
    return;

  recurser_void (n + 1);
}

void *trackpoint;

void __attribute__ ((noinline))
track (int n)
{
  char stackpos[1];

  if (n == 0)
    trackpoint = stackpos;
  else if (n != 7 || trackpoint != stackpos)
    abort ();
}
