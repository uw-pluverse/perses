







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

__attribute__((noinline, noclone)) void
fn1 (char *p, const char *z, size_t *lp)
{
  char *q, *r, *s;
  char buf[64];
  size_t l[11];





  l[0] = strlen (z);
  strcpy (buf, z);
  strcpy (p, "abcde");
  q = strchr (p, '\0');
  strcpy (q, "efghi");
  r = strchr (q, '\0');
  strcpy (r, buf);
  l[1] = strlen (p);
  l[2] = strlen (q);
  l[3] = strlen (r);
  strcpy (q, "jklmnopqrst");
  l[4] = strlen (p);
  l[5] = strlen (q);
  l[6] = strlen (r);
  s = strchr (q, '\0');
  strcpy (s, buf);
  l[7] = strlen (p);
  l[8] = strlen (q);
  l[9] = strlen (r);
  l[10] = strlen (s);
  memcpy (lp, l, sizeof l);
}

int
main ()
{
  char buf[64];
  size_t l[11];
  const char *volatile z = "ABCDEFG";
  memset (buf, '\0', sizeof buf);
  fn1 (buf, z, l);
  if (memcmp (buf, "abcdejklmnopqrstABCDEFG", 24) != 0)
    abort ();
  if (l[0] != 7)
    abort ();
  if (l[1] != 17 || l[2] != 12 || l[3] != 7)
    abort ();
  if (l[4] != 16 || l[5] != 11 || l[6] != 6)
    abort ();
  if (l[7] != 23 || l[8] != 18 || l[9] != 13 || l[10] != 7)
    abort ();
  return 0;
}
