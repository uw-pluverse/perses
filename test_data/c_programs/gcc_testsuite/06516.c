







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
foo (char *p, char *r)
{
  char buf[26];
  if (strlen (p) + strlen (r) + 9 > 26)
    return ((void *) 0);


  strcpy (buf, p);



  strcat (buf, "/");
  strcat (buf, "abcde");


  strcat (buf, r);

  strcat (buf, "fg");
  return strdup (buf);
}

int
main ()
{
  char *volatile p = "string1";
  char *volatile r = "string2";
  char *q = foo (p, r);
  if (q != ((void *) 0))
    {
      if (strcmp (q, "string1/abcdestring2fg"))
 abort ();
      free (q);
    }
  return 0;
}
