


void bar (void);
unsigned short
foo (unsigned char x, unsigned short y)
{
  unsigned char t = (unsigned char)((x & 1) ^ ((unsigned char)y & 1));
  if (t == 1)
    bar ();
  return y;
}
