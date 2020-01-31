extern void abort(void);
extern int inside_main;

typedef long unsigned int size_t;

__attribute__ ((__noinline__))
char *
strncat (char *s1, const char *s2, size_t n)
{
  char *dest = s1;
  char c = '\0';




  while (*s1) s1++;
  c = '\0';
  while (n > 0)
    {
      c = *s2++;
      *s1++ = c;
      if (c == '\0')
 return dest;
      n--;
    }
  if (c != '\0')
    *s1 = '\0';
  return dest;
}

