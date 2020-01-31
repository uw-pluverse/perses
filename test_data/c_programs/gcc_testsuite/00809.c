




void g (void);
void
foo (int x)
{
  if (x != 0x123456)
    g ();
}

void
fool (long long x)
{
  if (x != 0x123456)
    g ();
}
