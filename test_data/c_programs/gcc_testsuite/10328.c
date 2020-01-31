extern void abort (void);
extern void exit (int);

extern void recurser_void (void);
extern void track (void);

int n = 0;
int main ()
{
  recurser_void ();
  exit (0);
}

void
recurser_void (void)
{
  if (n == 0 || n == 7)
    track ();

  if (n == 10)
    return;
  n++;
  recurser_void ();
}

void *trackpoint;

void __attribute__ ((noinline))
track ()
{
  char stackpos[1];

  if (n == 0)
    trackpoint = stackpos;
  else if (n != 7 || trackpoint != stackpos)
    abort ();
}
