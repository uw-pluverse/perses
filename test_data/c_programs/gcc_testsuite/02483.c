extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
char *
stpcpy (char *dst, const char *src)
{





  while (*src != 0)
    *dst++ = *src++;

  *dst = 0;
  return dst;
}
