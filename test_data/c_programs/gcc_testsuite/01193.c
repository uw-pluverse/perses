





int foo (char *, char *, int);
int test (int d, char * out, char *in, int len)
{
  if (out != in)
    foo (out, in, len);
  return 0;
}
