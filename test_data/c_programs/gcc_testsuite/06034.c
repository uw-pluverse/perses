


powi_cost (long n)
{
  unsigned char cache[256];
  unsigned long digit;
  unsigned long val;
  int result;
  while (val >= 256)
    {
      if (val & 1)
 {
   result += powi_lookup_cost (digit, cache) + 3 + 1;
 }
      else
 {
   val >>= 1;
 }
    }
}
