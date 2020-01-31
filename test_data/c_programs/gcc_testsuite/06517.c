







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
fn1 (char *p, const char *r)
{
  size_t len1 = strlen (r);
  char *q = strchr (p, '\0');
  *q = '\0';
  return len1 - strlen (r);
}

int
main (void)
{
  char p[] = "foobar";
  const char *volatile q = "xyzzy";
  fn1 (p, q);
  return 0;
}
