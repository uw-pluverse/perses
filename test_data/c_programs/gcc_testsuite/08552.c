






unsigned short int count = 0;
int flag = 1;

extern void abort (void);
extern void exit (int);

int
main ()
{
  __sync_add_and_fetch (&count, -1);

  if (!flag)
    abort ();
  exit (0);
}
