



extern void abort (void);
extern void exit (int);

int
main (void)
{
  int a = 1;
  if (sizeof (*(++a, (char (*)[a])0)) != 2)
    abort ();
  exit (0);
}
