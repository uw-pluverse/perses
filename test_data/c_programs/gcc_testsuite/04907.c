






_Bool atomicvar, c;

int i, atomicvar2, c2;

int
foo (void)
{
 atomicvar |= -1;
 atomicvar |= 0;
 atomicvar |= 1;
 atomicvar |= 2;
 atomicvar |= c;
 atomicvar ^= -1;
 atomicvar ^= 0;
 atomicvar ^= 1;
 atomicvar ^= 2;
 atomicvar ^= c;
 atomicvar &= -1;
 atomicvar &= 0;
 atomicvar &= 1;
 atomicvar &= 2;
 atomicvar &= c;
 atomicvar += -1;
 atomicvar += 0;
 atomicvar += 1;
 atomicvar += 2;
 atomicvar += c;
 atomicvar -= -1;
 atomicvar -= 0;
 atomicvar -= 1;
 atomicvar -= 2;
 atomicvar -= c;
 atomicvar *= -1;
 atomicvar *= 0;
 atomicvar *= 1;
 atomicvar *= 2;
 atomicvar *= c;
 atomicvar /= -1;
 atomicvar /= 1;
 atomicvar /= 2;
 atomicvar /= c;
 atomicvar <<= 0;
 atomicvar <<= 1;
 atomicvar <<= 2;
 atomicvar <<= i;
 atomicvar >>= 0;
 atomicvar >>= 1;
 atomicvar >>= 2;
 atomicvar >>= i;
 atomicvar++;
 ++atomicvar;

 atomicvar--;
 --atomicvar;

 return 0;
}

int
bar (void)
{
 atomicvar2 |= -1;
 atomicvar2 |= 0;
 atomicvar2 |= 1;
 atomicvar2 |= 2;
 atomicvar2 |= c2;
 atomicvar2 ^= -1;
 atomicvar2 ^= 0;
 atomicvar2 ^= 1;
 atomicvar2 ^= 2;
 atomicvar2 ^= c2;
 atomicvar2 &= -1;
 atomicvar2 &= 0;
 atomicvar2 &= 1;
 atomicvar2 &= 2;
 atomicvar2 &= c2;
 atomicvar2 += -1;
 atomicvar2 += 0;
 atomicvar2 += 1;
 atomicvar2 += 2;
 atomicvar2 += c2;
 atomicvar2 -= -1;
 atomicvar2 -= 0;
 atomicvar2 -= 1;
 atomicvar2 -= 2;
 atomicvar2 -= c2;
 atomicvar2 *= -1;
 atomicvar2 *= 0;
 atomicvar2 *= 1;
 atomicvar2 *= 2;
 atomicvar2 *= c2;
 atomicvar2 /= -1;
 atomicvar2 /= 1;
 atomicvar2 /= 2;
 atomicvar2 /= c2;
 atomicvar2 <<= 0;
 atomicvar2 <<= 1;
 atomicvar2 <<= 2;
 atomicvar2 <<= i;
 atomicvar2 >>= 0;
 atomicvar2 >>= 1;
 atomicvar2 >>= 2;
 atomicvar2 >>= i;
 atomicvar2++;
 ++atomicvar2;
 atomicvar2--;
 --atomicvar2;
 return 0;
}

