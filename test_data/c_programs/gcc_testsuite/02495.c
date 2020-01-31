extern void abort(void);
extern int inside_main;

typedef long unsigned int size_t;

__attribute__ ((__noinline__))
char *
strncpy(char *s1, const char *s2, size_t n)
{
  char *dest = s1;




  for (; *s2 && n; n--)
    *s1++ = *s2++;
  while (n--)
    *s1++ = 0;
  return dest;
}
