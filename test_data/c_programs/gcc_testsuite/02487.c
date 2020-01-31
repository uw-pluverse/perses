extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
long unsigned int
strlen (const char *s)
{
  long unsigned int i;






  i = 0;
  while (s[i] != 0)
    i++;

  return i;
}
