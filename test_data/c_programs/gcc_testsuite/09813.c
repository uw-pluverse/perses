









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
fn1 (int x, int y, int z)
{
  static char buf[40];
  const char *p;
  switch (x)
    {
    case 0:
      p = "abcd";
      break;
    case 1:
      p = "efgh";
      break;
    case 2:
      p = "ijkl";
      break;
    default:
      p = "mnopq";
      break;
    }
  if (y)
    {
      strcpy (buf, p);
      if (z)
 strcat (buf, "ABCDEFG");
      else
 strcat (buf, "HIJKLMN");
    }
  else
    {
      strcpy (buf, p + 1);
      if (z)
 strcat (buf, "OPQ");
      else
 strcat (buf, "RST");
    }
  return buf;
}

int
main ()
{
  int i;
  for (i = 0; i < 5; i++)
    {
      const char *p = "abcdefghijklmnopq" + (i < 3 ? i : 3) * 4;
      const char *q;
      int j = i >= 3;
      fn1 (i ? 0 : 1, 1, 1);
      q = fn1 (i, 0, 0);
      if (memcmp (q, p + 1, 3 + j) != 0 || memcmp (q + 3 + j, "RST", 4) != 0)
 abort ();
      fn1 (i ? 0 : 1, 0, 1);
      q = fn1 (i, 1, 0);
      if (memcmp (q, p, 4 + j) != 0 || memcmp (q + 4 + j, "HIJKLMN", 8) != 0)
 abort ();
      fn1 (i ? 0 : 1, 1, 0);
      q = fn1 (i, 0, 1);
      if (memcmp (q, p + 1, 3 + j) != 0 || memcmp (q + 3 + j, "OPQ", 4) != 0)
 abort ();
      fn1 (i ? 0 : 1, 0, 0);
      q = fn1 (i, 1, 1);
      if (memcmp (q, p, 4 + j) != 0 || memcmp (q + 4 + j, "ABCDEFG", 8) != 0)
 abort ();
    }
  return 0;
}
