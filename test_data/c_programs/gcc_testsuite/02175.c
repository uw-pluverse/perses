
extern void abort (void);




int
main ()
{
  unsigned int u;
  int i = -1;

  u = (((unsigned int) ((i) > (0) ? (i) : (0))) > (1) ? ((unsigned int) ((i) > (0) ? (i) : (0))) : (1));
  if (u != 1)
    abort ();

  u = (((unsigned int) ((i) > (0) ? (i) : (0))) < ((unsigned int) i) ? ((unsigned int) ((i) > (0) ? (i) : (0))) : ((unsigned int) i));
  if (u != 0)
    abort ();
  return 0;
}
