




unsigned char g;

extern void abort ();

void
f (long long int p)
{
  g = 255;
  if (p >= -9223372036854775808LL - (signed char) g)
    p = 1;

  if (p)
    abort ();
}
