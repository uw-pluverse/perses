


char *my_alloc1 (int len) __attribute__((__assume_aligned__ (32)));
char *my_alloc2 (int len) __attribute__((assume_aligned (32, 4)));

int
test1 (int len)
{
  int i;
  char *p = my_alloc1 (len);
  return ((long int) p) & 31;
}

int
test2 (int len)
{
  int i;
  char *p = my_alloc2 (len);
  return (((long int) p) & 31) != 4;
}
