extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
char *
strcpy (char *d, const char *s)
{
  char *r = d;




  while ((*d++ = *s++));
  return r;
}
