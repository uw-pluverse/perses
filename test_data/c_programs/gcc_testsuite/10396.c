extern void *memset (void *, int, long unsigned int);
extern long unsigned int strlen (const char *);

int
main (int argc, char **argv)
{
  char x[8] = "abc";
  memset (x, argc, strlen (x));
  return 0;
}
