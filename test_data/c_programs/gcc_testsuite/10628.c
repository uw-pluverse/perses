












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

void *mempcpy (void *__restrict, const void *__restrict, size_t);
char *stpcpy (char *__restrict, const char *__restrict);






__attribute__((noinline, noclone)) void
foo (char *p, const char *q, const char *r)
{
  strcpy (p, q);
  strcat (p, r);
  strcat (p, "abcd");
}





__attribute__((noinline, noclone)) void
bar (char *p, const char *q, const char *r)
{
  strcpy (p, "abcd");
  strcat (p, q);
  strcat (p, r);
}







__attribute__((noinline, noclone)) void
baz (char *p, const char *q, const char *r)
{
  strcat (p, q);
  strcat (p, "abcd");
  strcat (p, r);
  strcat (p, "efgh");
}

char buf[64];

int
main ()
{
  char *volatile p = buf;
  const char *volatile q = "ij";
  const char *volatile r = "klmno";
  foo (p, q, r);
  if (memcmp (buf, "ijklmnoabcd\0\0\0\0\0\0\0\0", 20) != 0)
    abort ();
  memset (buf, '\0', sizeof buf);
  bar (p, q, r);
  if (memcmp (buf, "abcdijklmno\0\0\0\0\0\0\0\0", 20) != 0)
    abort ();
  memset (buf, 'v', 3);
  memset (buf + 3, '\0', -3 + sizeof buf);
  baz (p, q, r);
  if (memcmp (buf, "vvvijabcdklmnoefgh\0", 20) != 0)
    abort ();
  return 0;
}

