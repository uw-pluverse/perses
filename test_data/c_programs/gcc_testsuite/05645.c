


void a (void);
void b (void);

void
f (int i, float j, int i2, float j2)
{
  if (__builtin_expect ((i * i2) > 0 && __builtin_expect ((j * j2) != 0, 1), 0))
    a ();
  else
    b ();
}
