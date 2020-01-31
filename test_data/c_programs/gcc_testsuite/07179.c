







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

__attribute__((noinline, noclone)) size_t
fn1 (char *p, size_t l)
{
  memcpy (p, "abcdef", l);

  return strlen (p);
}

__attribute__((noinline, noclone)) size_t
fn2 (char *p, const char *q, size_t *lp)
{
  size_t l = strlen (q), l2;
  memcpy (p, q, 7);

  l2 = strlen (p);
  *lp = l;
  return l2;
}

__attribute__((noinline, noclone)) char *
fn3 (char *p)
{
  *p = 0;
  return p + 1;
}

int
main ()
{
  char buf[64];
  const char *volatile q = "ABCDEFGH";
  const char *volatile q2 = "IJ\0KLMNOPQRS";
  size_t l;
  memset (buf, '\0', sizeof buf);
  memset (buf + 2, 'a', 7);
  if (fn1 (buf, 3) != 9 || memcmp (buf, "abcaaaaaa", 10) != 0)
    abort ();
  if (fn1 (buf, 7) != 6 || memcmp (buf, "abcdef\0aa", 10) != 0)
    abort ();
  if (fn2 (buf, q, &l) != 9 || l != 8 || memcmp (buf, "ABCDEFGaa", 10) != 0)
    abort ();
  if (fn2 (buf, q2, &l) != 2 || l != 2 || memcmp (buf, "IJ\0KLMNaa", 10) != 0)
    abort ();
  if (fn3 (buf) != buf + 1 || memcmp (buf, "\0J\0KLMNaa", 10) != 0)
    abort ();
  return 0;
}
