







extern void abort (void);
extern void exit (int);
extern void _exit (int);
extern void _Exit (int);

extern void tabort (void);
extern void texit (void);
extern void t_exit (void);
extern void t_Exit (void);

extern void link_failure (void);




int
main (void)
{
  volatile int i = 0;
  if (i)
    tabort ();
  if (i)
    texit ();
  if (i)
    t_exit ();
  if (i)
    t_Exit ();
  exit (0);
}

void
tabort (void)
{
  abort ();
  link_failure ();
}

void
texit (void)
{
  exit (1);
  link_failure ();
}

void
t_exit (void)
{
  _exit (1);
  link_failure ();
}


void
_exit (int i)
{
  abort ();
}

void
t_Exit (void)
{
  _Exit (1);
  link_failure ();
}


void
_Exit (int i)
{
  abort ();
}
