static const char *
test (const char *in, char *out)
{
  while (1)
    {
      if (*in == 'a')
 {
   const char *p = in + 1;
   while (*p == 'x')
     ++p;
   if (*p == 'b')
     return p;
   while (in < p)
     *out++ = *in++;
 }
    }
}

int main ()
{
  char out[4];
  test ("aab", out);
  return 0;
}
