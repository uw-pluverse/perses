







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

char buf[64];

__attribute__((noinline, noclone)) size_t
foo (void)
{
  char *p = memcpy (buf, "abcdefgh", 9);

  *p = '\0';


  strcat (p, "ijk");

  return strlen (p);
}

__attribute__((noinline, noclone)) size_t
bar (char *p)
{
  char *r = strchr (p, '\0');


  *r = '\0';

  return strlen (r);
}

int
main ()
{
  char *volatile p = buf;
  if (foo () != 3 || memcmp (buf, "ijk\0efgh\0", 10) != 0)
    abort ();
  if (bar (p) != 0 || memcmp (buf, "ijk\0efgh\0", 10) != 0)
    abort ();
  return 0;
}
