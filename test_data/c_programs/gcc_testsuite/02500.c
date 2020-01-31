extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
long unsigned int
strcspn (const char *s1, const char *s2)
{
  const char *p, *q;






  for (p = s1; *p; p++)
    {
      for (q = s2; *q; q++)
 if (*p == *q)
   goto proceed;
      break;

    proceed:;
    }
  return p - s1;
}
