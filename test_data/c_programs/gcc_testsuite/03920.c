







typedef long unsigned int size_t;
size_t strlength (const char * const);
char foo();

static const char * const str = "mingo";

bar()
{
  size_t c;
  char *x;

  c = strlength (str);
  while (c < 10)
    {
      if (c > 5)
 *x = foo ();
      if (*x < 'a')
 break;
    }

  return *x == '3';
}
