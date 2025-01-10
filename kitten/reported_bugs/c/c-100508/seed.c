





typedef int __attribute__((__vector_size__(64))) U;
typedef __int128 __attribute__((__vector_size__(32))) V;

U i;
V j;

int
foo(unsigned char l)
{
  V m = j % 999;
  U n = l <= i;
  V o = ((union { U a; V b[2]; }) n).b[0] + m;
  return o[0];
}
