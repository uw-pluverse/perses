




typedef unsigned int char32_t;

extern void abort (void);

char32_t *s0 = U"a" U"b";

char32_t *s1 = U"a" "b";
char32_t *s2 = "a" U"b";
char32_t *s3 = U"a" "\u2029";
char32_t *s4 = "\u2029" U"b";
char32_t *s5 = U"a" "\U00064321";
char32_t *s6 = "\U00064321" U"b";






int main ()
{
    if (sizeof ((U"a" U"b")[0]) != sizeof (char32_t))
 abort ();
    if (sizeof ((U"a" "b")[0]) != sizeof (char32_t))
 abort ();
    if (sizeof (( "a" U"b")[0]) != sizeof (char32_t))
 abort ();

    if (s0[0] != 0x00000061 || s0[1] != 0x00000062 || s0[2] != 0x00000000)
 abort ();

    if (s1[0] != 0x00000061 || s1[1] != 0x00000062 || s1[2] != 0x00000000)
 abort ();
    if (s2[0] != 0x00000061 || s2[1] != 0x00000062 || s2[2] != 0x00000000)
 abort ();
    if (s3[0] != 0x00000061 || s3[1] != 0x00002029 || s3[2] != 0x00000000)
 abort ();
    if (s4[0] != 0x00002029 || s4[1] != 0x00000062 || s4[2] != 0x00000000)
 abort ();
    if (s5[0] != 0x00000061 || s5[1] != 0x00064321 || s5[2] != 0x00000000)
 abort ();
    if (s6[0] != 0x00064321 || s6[1] != 0x00000062 || s6[2] != 0x00000000)
 abort ();
}
