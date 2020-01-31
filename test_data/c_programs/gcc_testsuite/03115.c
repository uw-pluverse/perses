

void
bb_getopt_ulflags (char *s)
{
  for (;;)
    if (s[1])
      do
 s++;
      while (*s);
}
