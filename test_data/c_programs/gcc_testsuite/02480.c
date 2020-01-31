extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
void *
mempcpy (void *dst, const void *src, long unsigned int n)
{
  const char *srcp;
  char *dstp;






  srcp = src;
  dstp = dst;
  while (n-- != 0)
    *dstp++ = *srcp++;

  return dstp;
}
