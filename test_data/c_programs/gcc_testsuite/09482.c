




typedef unsigned int char32_t;

extern void abort (void);

char32_t c0 = U'a';
char32_t c1 = U'\0';
char32_t c2 = U'\u0024';
char32_t c3 = U'\u2029';
char32_t c4 = U'\U00064321';






int main ()
{
    if (sizeof (U'a') != sizeof (char32_t))
 abort ();
    if (sizeof (U'\0') != sizeof (char32_t))
 abort ();
    if (sizeof (U'\u0024') != sizeof (char32_t))
 abort ();
    if (sizeof (U'\u2029') != sizeof (char32_t))
 abort ();
    if (sizeof (U'\U00064321') != sizeof (char32_t))
 abort ();

    if (c0 != 0x00000061)
 abort ();
    if (c1 != 0x0000)
 abort ();
    if (c2 != 0x00000024)
 abort ();
    if (c3 != 0x00002029)
 abort ();
    if (c4 != 0x00064321)
 abort ();
}
