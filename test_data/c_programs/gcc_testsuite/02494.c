extern void abort(void);
extern int inside_main;

__attribute__ ((__noinline__))
void *
memchr (const void *s, int c, long unsigned int n)
{
  const unsigned char uc = c;
  const unsigned char *sp;






  sp = s;
  for (; n != 0; ++sp, --n)
    if (*sp == uc)
      return (void *) sp;

  return 0;
}
