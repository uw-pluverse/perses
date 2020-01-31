
int x();

extern void abort (void);

int
main ()
{
  if (x () == 7)
    return 0;
  abort ();
}
