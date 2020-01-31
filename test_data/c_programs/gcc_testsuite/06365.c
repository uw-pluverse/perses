



extern void abort (void);
extern char a[];

void foo (void)
{
  if ((void *) a == (void *) 0x4000UL)
    abort ();
}
