



typedef long unsigned int size_t;
extern



void *memset (void *, int, size_t);
char buf[1024];

void
foo ()
{
  memset (buf, sizeof buf, u'\0');
  memset (buf, sizeof buf, U'\0');
  memset (buf, u'\0', 0);
  memset (buf, U'\0', 0);
}
