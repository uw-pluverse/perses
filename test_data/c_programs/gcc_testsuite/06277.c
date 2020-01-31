




typedef unsigned int char32_t;

extern void abort (void);

char32_t *s0 = U"ab";
char32_t *s1 = U"a\u0024";
char32_t *s2 = U"a\u2029";
char32_t *s3 = U"a\U00064321";







int main ()
{
    if (s0[0] != 0x00000061 || s0[1] != 0x00000062 || s0[2] != 0x00000000)
 abort ();
    if (s1[0] != 0x00000061 || s1[1] != 0x00000024 || s0[2] != 0x00000000)
 abort ();
    if (s2[0] != 0x00000061 || s2[1] != 0x00002029 || s0[2] != 0x00000000)
 abort ();
    if (s3[0] != 0x00000061 || s3[1] != 0x00064321 || s3[2] != 0x00000000)
 abort ();
}
