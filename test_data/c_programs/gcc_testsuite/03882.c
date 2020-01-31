



void bar (void);

int
foo (int i)
{
  static const void *const table[] = { &&begin, &&end };
  goto *(table[i]);
begin:
  bar ();
end:
  return 0;
}
