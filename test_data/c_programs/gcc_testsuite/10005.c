extern void abort (void);
extern void exit (int);
static void recurser_void1 (int);
static void recurser_void2 (int);
extern void track (int);
volatile int v;

int main ()
{
  recurser_void1 (0);
  if (v != 5)
    abort ();
  exit (0);
}





static void __attribute__((noinline))
recurser_void1 (int n)
{
  if (n == 0 || n == 7 || n == 8)
    track (n);

  if (n == 10)
    return;

  recurser_void2 (n + 1);
}

static void __attribute__((noinline))
recurser_void2 (int n)
{
  if (n == 0 || n == 7 || n == 8)
    track (n);

  if (n == 10)
    return;

  v++;
  recurser_void1 (n + 1);
}

void *trackpoint;

void __attribute__ ((noinline))
track (int n)
{
  char stackpos[1];

  if (n == 0)
    trackpoint = stackpos;
  else if ((n != 7 && n != 8) || trackpoint != stackpos)
    abort ();
}
