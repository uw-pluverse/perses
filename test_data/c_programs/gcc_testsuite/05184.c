extern void link_error (void);

unsigned int d;
unsigned long e;
unsigned long long f;

void
foo (int a, long b, long long c)
{
  if (__builtin_ffs (a) < 0 || __builtin_ffs (a) > ((int) sizeof (a) * 8 - 0)) link_error (); if (__builtin_ffsl (b) < 0 || __builtin_ffsl (b) > ((int) sizeof (b) * 8 - 0)) link_error (); if (__builtin_ffsll (c) < 0 || __builtin_ffsll (c) > ((int) sizeof (c) * 8 - 0)) link_error ();
  a &= 63; b &= 63; c &= 63;
  if (__builtin_ffs (a) < 0 || __builtin_ffs (a) > 6) link_error (); if (__builtin_ffsl (b) < 0 || __builtin_ffsl (b) > 6) link_error (); if (__builtin_ffsll (c) < 0 || __builtin_ffsll (c) > 6) link_error ();
  a++; b++; c++;
  if (__builtin_ffs (a) < 1 || __builtin_ffs (a) > 7) link_error (); if (__builtin_ffsl (b) < 1 || __builtin_ffsl (b) > 7) link_error (); if (__builtin_ffsll (c) < 1 || __builtin_ffsll (c) > 7) link_error ();
  a -= 2; b -= 2; c -= 2;
  if (__builtin_ffs (a) < 0 || __builtin_ffs (a) > ((int) sizeof (a) * 8 - 0)) link_error (); if (__builtin_ffsl (b) < 0 || __builtin_ffsl (b) > ((int) sizeof (b) * 8 - 0)) link_error (); if (__builtin_ffsll (c) < 0 || __builtin_ffsll (c) > ((int) sizeof (c) * 8 - 0)) link_error ();
  a -= 63; b -= 63; c -= 63;
  if (__builtin_ffs (a) < 1 || __builtin_ffs (a) > ((int) sizeof (a) * 8 - 0)) link_error (); if (__builtin_ffsl (b) < 1 || __builtin_ffsl (b) > ((int) sizeof (b) * 8 - 0)) link_error (); if (__builtin_ffsll (c) < 1 || __builtin_ffsll (c) > ((int) sizeof (c) * 8 - 0)) link_error ();
}
