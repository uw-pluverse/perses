int foo()
{
  char f = 0x83;
  if (f == '\x83')
    f = 0;

  return 0;
}
