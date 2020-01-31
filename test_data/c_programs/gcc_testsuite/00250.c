

extern void abort (void);
extern void exit (int);

short foo = 1;
int main ()
{
  char *p = (char *) &foo;




  if (p[0] != 1 || p[1] != 0)

    abort ();
  exit (0);
}
