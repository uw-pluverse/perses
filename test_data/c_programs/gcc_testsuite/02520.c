extern void abort (void);
extern int inside_main;
typedef long unsigned int size_t;





__attribute__ ((used))
void *
my_memcpy (void *d, const void *s, size_t n)
{
  char *dst = (char *) d;
  const char *src = (const char *) s;
  while (n--)
    *dst++ = *src++;
  return (char *) d;
}



__attribute__ ((used))
void
my_bcopy (const void *s, void *d, size_t n)
{
  char *dst = (char *) d;
  const char *src = (const char *) s;
  if (src >= dst)
    while (n--)
      *dst++ = *src++;
  else
    {
      dst += n;
      src += n;
      while (n--)
        *--dst = *--src;
    }
}



__attribute__ ((used))
void *
my_memset (void *d, int c, size_t n)
{
  char *dst = (char *) d;
  while (n--)
    *dst++ = c;
  return (char *) d;
}



__attribute__ ((used))
void
my_bzero (void *d, size_t n)
{
  char *dst = (char *) d;
  while (n--)
    *dst++ = '\0';
}

void *
memcpy (void *d, const void *s, size_t n)
{
  void *result = my_memcpy (d, s, n);
  if (inside_main) abort();
  return result;
}

void
bcopy (const void *s, void *d, size_t n)
{
  my_bcopy (s, d, n);
  if (inside_main) abort();
}

void *
memset (void *d, int c, size_t n)
{
  void *result = my_memset (d, c, n);
  if (inside_main) abort();
  return result;
}

void
bzero (void *d, size_t n)
{
  my_bzero (d, n);
  if (inside_main) abort();
}
