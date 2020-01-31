







typedef long unsigned int size_t;
extern void abort (void);
void *malloc (size_t);
void free (void *);
char *strdup (const char *);
size_t strlen (const char *);
void *memcpy (void *__restrict, const void *__restrict, size_t);
void *memmove (void *, const void *, size_t);
char *strcpy (char *__restrict, const char *__restrict);
char *strcat (char *__restrict, const char *__restrict);
char *strchr (const char *, int);
void *memset (void *, int, size_t);
int memcmp (const void *, const void *, size_t);
int strcmp (const char *, const char *);

struct S { char *p; size_t l; };

__attribute__((noinline, noclone)) struct S
foo (char *x, int n)
{
  int i;
  char a[64];
  char *p = strchr (x, '\0');
  struct S s;

  strcpy (a, x);

  strcat (p, "abcd");
  for (i = 0; i < n; i++)
    if ((i % 123) == 53)

      strcat (a, "efg");
  s.p = strdup (a);

  s.l = strlen (p);
  return s;
}

int
main ()
{
  char buf[32];
  struct S s;
  buf[0] = 'z';
  buf[1] = '\0';
  s = foo (buf, 0);
  if (s.l != 4 || memcmp (buf, "zabcd", 6) != 0)
    abort ();
  if (s.p == ((void *) 0))
    return 0;
  if (memcmp (s.p, "z", 2) != 0)
    abort ();
  s = foo (buf, 60);
  if (s.l != 4 || memcmp (buf, "zabcdabcd", 10) != 0)
    abort ();
  if (s.p == ((void *) 0))
    return 0;
  if (memcmp (s.p, "zabcdefg", 9) != 0)
    abort ();
  s = foo (buf, 240);
  if (s.l != 4 || memcmp (buf, "zabcdabcdabcd", 14) != 0)
    abort ();
  if (s.p == ((void *) 0))
    return 0;
  if (memcmp (s.p, "zabcdabcdefgefg", 16) != 0)
    abort ();
  return 0;
}
