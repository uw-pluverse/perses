


void g (void);

void
f (int i, float j, int i2, float j2)
{
  if (__builtin_expect ((i * i2) > 0 || (j * j2), 0))
    ;
  else
    g ();
}
