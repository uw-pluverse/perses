


typedef long unsigned int size_t;
extern



void *memset (void *, int, size_t);
char buf[1024];

void
foo ()
{
  memset (buf, sizeof buf, 0);
  memset (buf, sizeof buf, '\0');
  memset (buf, sizeof buf, L'\0');
  memset (buf, 1, 1 - 1);
  memset (buf, 1, 0 - 0);
  memset (buf, 0, 0);
  memset (buf, '\0', 0);
  memset (buf, L'\0', 0);
  memset (buf, 1 - 1, 0);
  memset (buf, 0 - 0, 0);
  memset (buf, sizeof buf, 0L);
  memset (buf, sizeof buf, 0UL);
  memset (buf, sizeof buf, 0LL);
  memset (buf, sizeof buf, 0ULL);
  memset (buf, sizeof buf, (int) 0);
  memset (buf, sizeof buf, -0);
}
