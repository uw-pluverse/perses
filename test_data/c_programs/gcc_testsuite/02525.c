extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
void *
memset (void *dst, int c, long unsigned int n)
{
  while (n-- != 0)
    n[(char *) dst] = c;
  return dst;
}

