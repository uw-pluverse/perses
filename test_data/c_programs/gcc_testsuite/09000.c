







typedef unsigned long uns32_t;
typedef unsigned long long uns64_t;

extern void abort(void);

uns32_t lo (uns64_t p)
{
  return (uns32_t)p;
}

uns64_t concat (uns32_t p1, uns32_t p2)
{

  return ((uns64_t)p1 << 32) | p2;



}

uns64_t lshift32 (uns64_t p1, uns32_t p2)
{
  return concat (lo (p1), p2);
}

int main(void)
{

  if (lshift32 (0xFFFFFFFF12345678ULL, 0x90ABCDEFUL) != 0x1234567890ABCDEFULL)
    abort ();


  return 0;
}
