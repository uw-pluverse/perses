







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

__attribute__((noinline, noclone)) char *
fn1 (char *p, size_t *l1, size_t *l2)
{
  char *a = mempcpy (p, "abcde", 6);

  size_t la = strlen (a);

  size_t lp = strlen (p);
  *l1 = la;
  *l2 = lp;
  return a;
}

__attribute__((noinline, noclone)) char *
fn2 (char *p, const char *q, size_t *l1, size_t *l2, size_t *l3)
{

  size_t lq = strlen (q);
  char *a = mempcpy (p, q, lq + 1);

  size_t la = strlen (a);

  size_t lp = strlen (p);
  *l1 = lq;
  *l2 = la;
  *l3 = lp;
  return a;
}

__attribute__((noinline, noclone)) char *
fn3 (char *p, size_t *l1, size_t *l2)
{
  char *a = stpcpy (p, "abcde");

  size_t la = strlen (a);

  size_t lp = strlen (p);
  *l1 = la;
  *l2 = lp;
  return a;
}

__attribute__((noinline, noclone)) char *
fn4 (char *p, const char *q, size_t *l1, size_t *l2, size_t *l3)
{

  size_t lq = strlen (q);
  char *a = stpcpy (p, q);

  size_t la = strlen (a);

  size_t lp = strlen (p);
  *l1 = lq;
  *l2 = la;
  *l3 = lp;
  return a;
}

__attribute__((noinline, noclone)) char *
fn5 (char *p, const char *q, size_t *l1, size_t *l2)
{
  char *a = stpcpy (p, q);

  size_t la = strlen (a);

  size_t lp = strlen (p);
  *l1 = la;
  *l2 = lp;
  return a;
}

int
main ()
{
  char buf[64];
  const char *volatile q = "ABCDEFGH";
  size_t l1, l2, l3;
  memset (buf, '\0', sizeof buf);
  memset (buf + 6, 'z', 7);
  if (fn1 (buf, &l1, &l2) != buf + 6 || l1 != 7 || l2 != 5
      || memcmp (buf, "abcde\0zzzzzzz", 14) != 0)
    abort ();
  if (fn2 (buf, q, &l1, &l2, &l3) != buf + 9 || l1 != 8 || l2 != 4 || l3 != 8
      || memcmp (buf, "ABCDEFGH\0zzzz", 14) != 0)
    abort ();
  if (fn3 (buf, &l1, &l2) != buf + 5 || l1 != 0 || l2 != 5
      || memcmp (buf, "abcde\0GH\0zzzz", 14) != 0)
    abort ();
  l3 = 0;
  memset (buf, 'n', 9);
  if (fn4 (buf, q, &l1, &l2, &l3) != buf + 8 || l1 != 8 || l2 != 0 || l3 != 8
      || memcmp (buf, "ABCDEFGH\0zzzz", 14) != 0)
    abort ();
  memset (buf, 'm', 9);
  if (fn5 (buf, q, &l1, &l2) != buf + 8 || l1 != 0 || l2 != 8
      || memcmp (buf, "ABCDEFGH\0zzzz", 14) != 0)
    abort ();
  return 0;
}

