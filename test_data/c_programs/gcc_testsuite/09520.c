







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

__attribute__((noinline, noclone)) char *
foo (char *x)
{
  char b[64];
  char *q = malloc (strlen (x) + 64);
  char *p = strcpy (b, x);

  char *r;
  if (q == ((void *) 0)) return ((void *) 0);


  *q = '\0';

  strcat (q, p);
  strcat (q, "/");


  r = strchr (q, '\0');


  *r = '\0';

  strcat (q, "abcde");
  return q;
}

__attribute__((noinline, noclone)) char *
bar (char *p)
{
  char buf[26];
  char *r;
  if (strlen (p) + 9 > 26)
    return ((void *) 0);
  *buf = '\0';
  strcat (buf, p);
  strcat (buf, "/");
  r = strchr (buf, '\0');
  *r = '\0';
  strcat (buf, "abcde");
  return strdup (buf);
}

int
main ()
{
  char *volatile p = "string1";
  char *volatile r = "string2";
  char *q = foo (p);
  if (q != ((void *) 0))
    {
      if (strcmp (q, "string1/abcde"))
 abort ();
      memset (q, '\0', 14);
      free (q);
    }
  q = bar (p);
  if (q != ((void *) 0))
    {
      if (strcmp (q, "string1/abcde"))
 abort ();
      free (q);
    }
  return 0;
}
