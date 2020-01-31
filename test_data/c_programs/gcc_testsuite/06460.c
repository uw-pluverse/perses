extern void abort (void);
extern void exit (int);
static void recurser_void1 (void);
static void recurser_void2 (void);
extern void track (void);
volatile int v;

int n = 0;
int main ()
{
  recurser_void1 ();
  if (v != 5)
    abort ();
  exit (0);
}





static void __attribute__((noinline))
recurser_void1 (void)
{
  if (n == 0 || n == 7 || n == 8)
    track ();

  if (n == 10)
    return;
  n++;
  recurser_void2 ();
}

static void __attribute__((noinline))
recurser_void2 (void)
{
  if (n == 0 || n == 7 || n == 8)
    track ();

  if (n == 10)
    return;
  n++;
  v++;
  recurser_void1 ();
}

void *trackpoint;

void __attribute__ ((noinline))
track ()
{
  char stackpos[1];

  if (n == 0)
    trackpoint = stackpos;
  else if ((n != 7 && n != 8) || trackpoint != stackpos)
    abort ();
}
