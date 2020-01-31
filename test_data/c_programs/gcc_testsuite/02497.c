extern int inside_main;

__attribute__ ((__noinline__))
void
bfill (void *s, long unsigned int n, int ch)
{
  char *p;

  for (p = s; n-- > 0; p++)
    *p = ch;





}
