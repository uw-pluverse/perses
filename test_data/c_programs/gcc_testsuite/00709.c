


extern void abort (void);
__uint128_t __attribute__ ((noinline))ushift_53_i (unsigned int data){ return (__uint128_t) data << 53;}__int128_t __attribute__ ((noinline)) shift_53_i (int data) { return (__int128_t) data << 53;}
__uint128_t __attribute__ ((noinline))ushift_3_ll (unsigned long long data){ return (__uint128_t) data << 3;}__int128_t __attribute__ ((noinline)) shift_3_ll (long long data) { return (__int128_t) data << 3;}
__uint128_t __attribute__ ((noinline))ushift_13_ll (unsigned long long data){ return (__uint128_t) data << 13;}__int128_t __attribute__ ((noinline)) shift_13_ll (long long data) { return (__int128_t) data << 13;}
__uint128_t __attribute__ ((noinline))ushift_53_ll (unsigned long long data){ return (__uint128_t) data << 53;}__int128_t __attribute__ ((noinline)) shift_53_ll (long long data) { return (__int128_t) data << 53;}

int
main (int argc, char **argv)
{
  if (ushift_53_i (0x12345678) != ((__uint128_t) (unsigned int) 0x12345678 << 53)) abort (); if (shift_53_i (0x12345678) != ((__uint128_t) (signed int) 0x12345678 << 53)) abort ();
  if (ushift_53_i (0xcafecafe) != ((__uint128_t) (unsigned int) 0xcafecafe << 53)) abort (); if (shift_53_i (0xcafecafe) != ((__uint128_t) (signed int) 0xcafecafe << 53)) abort ();

  if (ushift_3_ll (0x1234567890abcdefLL) != ((__uint128_t) (unsigned long long) 0x1234567890abcdefLL << 3)) abort (); if (shift_3_ll (0x1234567890abcdefLL) != ((__uint128_t) (signed long long) 0x1234567890abcdefLL << 3)) abort ();
  if (ushift_13_ll (0x1234567890abcdefLL) != ((__uint128_t) (unsigned long long) 0x1234567890abcdefLL << 13)) abort (); if (shift_13_ll (0x1234567890abcdefLL) != ((__uint128_t) (signed long long) 0x1234567890abcdefLL << 13)) abort ();
  if (ushift_53_ll (0x1234567890abcdefLL) != ((__uint128_t) (unsigned long long) 0x1234567890abcdefLL << 53)) abort (); if (shift_53_ll (0x1234567890abcdefLL) != ((__uint128_t) (signed long long) 0x1234567890abcdefLL << 53)) abort ();
  if (ushift_3_ll (0xcafecafedeaddeadLL) != ((__uint128_t) (unsigned long long) 0xcafecafedeaddeadLL << 3)) abort (); if (shift_3_ll (0xcafecafedeaddeadLL) != ((__uint128_t) (signed long long) 0xcafecafedeaddeadLL << 3)) abort ();
  if (ushift_13_ll (0xcafecafedeaddeadLL) != ((__uint128_t) (unsigned long long) 0xcafecafedeaddeadLL << 13)) abort (); if (shift_13_ll (0xcafecafedeaddeadLL) != ((__uint128_t) (signed long long) 0xcafecafedeaddeadLL << 13)) abort ();
  if (ushift_53_ll (0xcafecafedeaddeadLL) != ((__uint128_t) (unsigned long long) 0xcafecafedeaddeadLL << 53)) abort (); if (shift_53_ll (0xcafecafedeaddeadLL) != ((__uint128_t) (signed long long) 0xcafecafedeaddeadLL << 53)) abort ();

  return 0;
}
