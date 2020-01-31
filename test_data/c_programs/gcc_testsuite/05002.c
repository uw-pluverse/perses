




extern void abort (void);
signed __int128 foo_neg (signed __int128 v)
{
  return -v;
}

unsigned __int128 foo_xor (unsigned __int128 x, unsigned __int128 y)
{
  return x ^ y;
}

unsigned __int128 foo_inv (unsigned __int128 v)
{
  return ~v;
}

unsigned __int128 foo_rotate_left (unsigned __int128 v)
{
  unsigned __int128 c;
  int i;
  for (i = 0; i < 128; i++)
    {
      c = v >> 127;
      v <<= 1;
      v |= c;
    }
  return v;
}

unsigned __int128 foo_rotate_right (unsigned __int128 v)
{
  unsigned __int128 c;
  int i;
  for (i = 0; i < 128; i++)
    {
      c = (v & ((unsigned __int128) 1)) << 127;
      v >>= 1;
      v |= c;
    }
  return v;
}

void foo_swap (unsigned __int128 *x, unsigned __int128 *y)
{
  unsigned __int128 x1 = x[0];
  unsigned __int128 y1 = y[0];
  x1 ^= y1 ^= x1 ^= y1;
  x[0] = x1;
  y[0] = y1;
}

__int128 foo_add (signed __int128 a, unsigned __int128 b)
{
  return (__int128) (a + (__int128) b);
}

__int128 foo_sub (unsigned __int128 a, signed __int128 b)
{
  return (__int128) ((__int128) a - b);
}

__int128 foo_mul (signed __int128 a, signed __int128 b)
{
  return a * b;
}

__int128 foo_div (signed __int128 a, signed __int128 b)
{
  return a / b;
}

__int128 foo_shl (signed __int128 a, int shift)
{
  return a << (shift & 127);
}

__int128 foo_shr (signed __int128 a, int shift)
{
  return a >> (shift & 127);
}

int main(void)
{
  __int128 rslt;
  unsigned __int128 u1, u2;

  rslt = foo_add (((__int128) ( (((unsigned __int128) (unsigned int) 0xffffffffu) << 96) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 64) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 32) | ((unsigned __int128) (unsigned int) 0xfffffffeu) )), ( (((unsigned __int128) (unsigned int) 0) << 96) | (((unsigned __int128) (unsigned int) 0) << 64) | (((unsigned __int128) (unsigned int) 0) << 32) | ((unsigned __int128) (unsigned int) 8) ));
  if (rslt != ((__int128) ( (((unsigned __int128) (unsigned int) 0) << 96) | (((unsigned __int128) (unsigned int) 0) << 64) | (((unsigned __int128) (unsigned int) 0) << 32) | ((unsigned __int128) (unsigned int) 6) )))
    abort ();
  rslt = foo_sub (( (((unsigned __int128) (unsigned int) 0) << 96) | (((unsigned __int128) (unsigned int) 0) << 64) | (((unsigned __int128) (unsigned int) 0) << 32) | ((unsigned __int128) (unsigned int) 8) ), ((__int128) ( (((unsigned __int128) (unsigned int) 0xffffffffu) << 96) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 64) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 32) | ((unsigned __int128) (unsigned int) 0xfffffffeu) )));
  if (rslt != ((__int128) ( (((unsigned __int128) (unsigned int) 0) << 96) | (((unsigned __int128) (unsigned int) 0) << 64) | (((unsigned __int128) (unsigned int) 0) << 32) | ((unsigned __int128) (unsigned int) 10) )))
     abort ();
  rslt = foo_sub ((unsigned __int128) foo_mul (((__int128) ( (((unsigned __int128) (unsigned int) 0xffffffffu) << 96) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 64) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 32) | ((unsigned __int128) (unsigned int) 0xfffffffeu) )), ((__int128) ( (((unsigned __int128) (unsigned int) 0xffffffffu) << 96) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 64) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 32) | ((unsigned __int128) (unsigned int) 0xfffffffeu) ))), ((__int128) ( (((unsigned __int128) (unsigned int) 0xffffffffu) << 96) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 64) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 32) | ((unsigned __int128) (unsigned int) 0xfffffffeu) )));
  if (rslt != ((__int128) ( (((unsigned __int128) (unsigned int) 0) << 96) | (((unsigned __int128) (unsigned int) 0) << 64) | (((unsigned __int128) (unsigned int) 0) << 32) | ((unsigned __int128) (unsigned int) 6) )))
    abort ();
  if (rslt != foo_shl (((__int128) ( (((unsigned __int128) (unsigned int) 0) << 96) | (((unsigned __int128) (unsigned int) 0) << 64) | (((unsigned __int128) (unsigned int) 0) << 32) | ((unsigned __int128) (unsigned int) 3) )), 1))
    abort ();
  rslt = foo_shl (((__int128) ( (((unsigned __int128) (unsigned int) 0xffffffffu) << 96) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 64) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 32) | ((unsigned __int128) (unsigned int) 0xfffffffdu) )), 1);
  if (rslt != ((__int128) ( (((unsigned __int128) (unsigned int) 0xffffffffu) << 96) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 64) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 32) | ((unsigned __int128) (unsigned int) 0xfffffffau) )))
    abort ();
  if (foo_shr (((__int128) ( (((unsigned __int128) (unsigned int) 0xffffffffu) << 96) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 64) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 32) | ((unsigned __int128) (unsigned int) 0xfffffffau) )), 1) != ((__int128) ( (((unsigned __int128) (unsigned int) 0xffffffffu) << 96) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 64) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 32) | ((unsigned __int128) (unsigned int) 0xfffffffdu) )))
    abort ();
  if (foo_div (((__int128) ( (((unsigned __int128) (unsigned int) 0xffffffffu) << 96) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 64) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 32) | ((unsigned __int128) (unsigned int) 0xfffffffau) )), ((__int128) ( (((unsigned __int128) (unsigned int) 0xffffffffu) << 96) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 64) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 32) | ((unsigned __int128) (unsigned int) 0xfffffffdu) ))) != ((__int128) ( (((unsigned __int128) (unsigned int) 0) << 96) | (((unsigned __int128) (unsigned int) 0) << 64) | (((unsigned __int128) (unsigned int) 0) << 32) | ((unsigned __int128) (unsigned int) 2) )))
    abort ();
  if (foo_rotate_left (( (((unsigned __int128) (unsigned int) 0xbeeffeed) << 96) | (((unsigned __int128) (unsigned int) 0xdeafcafe) << 64) | (((unsigned __int128) (unsigned int) 0xaffefade) << 32) | ((unsigned __int128) (unsigned int) 0x12345678) )) != ( (((unsigned __int128) (unsigned int) 0xbeeffeed) << 96) | (((unsigned __int128) (unsigned int) 0xdeafcafe) << 64) | (((unsigned __int128) (unsigned int) 0xaffefade) << 32) | ((unsigned __int128) (unsigned int) 0x12345678) ))
    abort ();
  if (foo_rotate_right (( (((unsigned __int128) (unsigned int) 0xbeeffeed) << 96) | (((unsigned __int128) (unsigned int) 0xdeafcafe) << 64) | (((unsigned __int128) (unsigned int) 0xaffefade) << 32) | ((unsigned __int128) (unsigned int) 0x12345678) )) != ( (((unsigned __int128) (unsigned int) 0xbeeffeed) << 96) | (((unsigned __int128) (unsigned int) 0xdeafcafe) << 64) | (((unsigned __int128) (unsigned int) 0xaffefade) << 32) | ((unsigned __int128) (unsigned int) 0x12345678) ))
    abort ();
  u1 = ( (((unsigned __int128) (unsigned int) 0xbeeffeed) << 96) | (((unsigned __int128) (unsigned int) 0xdeafcafe) << 64) | (((unsigned __int128) (unsigned int) 0xaffefade) << 32) | ((unsigned __int128) (unsigned int) 0x12345678) );
  u2 = ( (((unsigned __int128) (unsigned int) 0) << 96) | (((unsigned __int128) (unsigned int) 0) << 64) | (((unsigned __int128) (unsigned int) 0) << 32) | ((unsigned __int128) (unsigned int) 8) );
  foo_swap (&u1, &u2);
  if (u1 != ( (((unsigned __int128) (unsigned int) 0) << 96) | (((unsigned __int128) (unsigned int) 0) << 64) | (((unsigned __int128) (unsigned int) 0) << 32) | ((unsigned __int128) (unsigned int) 8) ) || u2 != ( (((unsigned __int128) (unsigned int) 0xbeeffeed) << 96) | (((unsigned __int128) (unsigned int) 0xdeafcafe) << 64) | (((unsigned __int128) (unsigned int) 0xaffefade) << 32) | ((unsigned __int128) (unsigned int) 0x12345678) ))
    abort ();

  if (foo_inv (( (((unsigned __int128) (unsigned int) 0x41100112) << 96) | (((unsigned __int128) (unsigned int) 0x21503501) << 64) | (((unsigned __int128) (unsigned int) 0x50010521) << 32) | ((unsigned __int128) (unsigned int) 0xedcba987) )) != ( (((unsigned __int128) (unsigned int) 0xbeeffeed) << 96) | (((unsigned __int128) (unsigned int) 0xdeafcafe) << 64) | (((unsigned __int128) (unsigned int) 0xaffefade) << 32) | ((unsigned __int128) (unsigned int) 0x12345678) ))
    abort ();
  if (foo_neg (((__int128) ( (((unsigned __int128) (unsigned int) 0) << 96) | (((unsigned __int128) (unsigned int) 0) << 64) | (((unsigned __int128) (unsigned int) 0) << 32) | ((unsigned __int128) (unsigned int) 2) ))) != ((__int128) ( (((unsigned __int128) (unsigned int) 0xffffffffu) << 96) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 64) | (((unsigned __int128) (unsigned int) 0xffffffffu) << 32) | ((unsigned __int128) (unsigned int) 0xfffffffeu) )))
    abort ();
  if (foo_neg ((signed __int128) ( (((unsigned __int128) (unsigned int) 0xbeeffeed) << 96) | (((unsigned __int128) (unsigned int) 0xdeafcafe) << 64) | (((unsigned __int128) (unsigned int) 0xaffefade) << 32) | ((unsigned __int128) (unsigned int) 0x12345678) )) != foo_add (((__int128) ( (((unsigned __int128) (unsigned int) 0) << 96) | (((unsigned __int128) (unsigned int) 0) << 64) | (((unsigned __int128) (unsigned int) 0) << 32) | ((unsigned __int128) (unsigned int) 1) )), foo_xor (( (((unsigned __int128) (unsigned int) 0xbeeffeed) << 96) | (((unsigned __int128) (unsigned int) 0xdeafcafe) << 64) | (((unsigned __int128) (unsigned int) 0xaffefade) << 32) | ((unsigned __int128) (unsigned int) 0x12345678) ), ( (((unsigned __int128) (unsigned int) 0xffffffff) << 96) | (((unsigned __int128) (unsigned int) 0xffffffff) << 64) | (((unsigned __int128) (unsigned int) 0xffffffff) << 32) | ((unsigned __int128) (unsigned int) 0xffffffff) ))))
    abort ();
  return 0;
}
