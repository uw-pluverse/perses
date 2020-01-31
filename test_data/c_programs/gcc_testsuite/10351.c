







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
bar (char *p, char *q)
{
  size_t l1, l2, l3;
  char *r = strchr (p, '\0');
  strcpy (r, "abcde");
  char *s = strchr (r, '\0');
  strcpy (s, q);
  l1 = strlen (p);
  l2 = strlen (r);
  l3 = strlen (s);
  return l1 + l2 + l3;
}

int
main ()
{
  char buf[16] = "01234";

  if (bar (buf, "56789") != 30)
    abort ();

  if (memcmp (buf, "01234abcde56789", 16) != 0)
    abort ();

  return 0;
}
