extern int inside_main;

__attribute__ ((__noinline__))
void
bzero (void *s, long unsigned int n)
{
  char *p;

  for (p = s; n-- > 0; p++)
    *p = 0;





}
