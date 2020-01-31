extern void abort (void);

typedef struct giga
{
  unsigned int g[16];
} giga;

unsigned long __attribute__((noinline,noclone))
addfst(giga const *gptr, int num)
{
  unsigned int retval = 0;
  int i;
  for (i = 0; i < num; i++)
    retval += gptr[i].g[0];
  return retval;
}

int main ()
{
  struct giga g[8];
  unsigned int n = 1;
  int i, j;
  for (i = 0; i < 8; ++i)
    for (j = 0; j < 16; ++j)
      {
 g[i].g[j] = n++;
 __asm__ volatile ("");
      }
  if (addfst (g, 8) != 456)
    abort ();
  return 0;
}
