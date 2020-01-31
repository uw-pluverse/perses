


typedef long int ssize_t;
ssize_t foo (ssize_t x)
{
  return (ssize_t)(char *)x;
}

char *bar (char *x)
{
  return (char *)(ssize_t)x;
}
