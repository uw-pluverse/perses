


extern void g (void);
int
f (int i)
{
  if (i & 0x0ffff000)
    g ();
}
