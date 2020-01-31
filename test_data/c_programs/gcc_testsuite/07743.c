



char *p;

void foo ()
{
  p = "abc\n";

  while (*p != '\n')
    p++;
}
