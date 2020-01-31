




char *strcpy (char *dest, const char *src);

void test (char *Line, int len)
{
  int z;

  for (z = 1; z <= len; z++)
    if (Line[z - 1])
      strcpy (Line + z + 1, Line);
}
