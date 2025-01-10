



__uint128_t
foo (__uint128_t x)
{
  return x + ((__uint128_t) 123456 << 64) + 0x1234567;
}

__uint128_t
bar (__uint128_t x)
{
  return x - ((__uint128_t) 123456 << 64) + 0x1234567;
}
