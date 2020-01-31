int main()
{
  int __s, __v = 17;
  int __t;
  __asm__ __volatile__(
      "addi %0,%1,%2 \n\t\t"
      : "=c" (__t)
        : "c" (__s), "I" (__v));
  int i_temp = 44;
  int i_result;
  __asm__ __volatile__(
      "mtlo %1 \n\t\t"
      : "=l" (i_result)
        : "r" (i_temp)
          : "lo");
  int i_hi = 3;
  int i_lo = 2;
  long long ll_result = 0;
  __asm__ __volatile__(
      "mthi %1 \n\t\t"
      "mtlo %2 \n\t\t"
      : "=x" (ll_result)
        : "r" (i_hi), "r" (i_lo)
          : );
  return 0;
}
