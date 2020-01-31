




typedef unsigned short char16_t;

extern void abort (void);

char16_t c0 = u'a';
char16_t c1 = u'\0';
char16_t c2 = u'\u0024';
char16_t c3 = u'\u2029';
char16_t c4 = u'\u8010';

char16_t c5 = 'a';
char16_t c6 = U'a';
char16_t c7 = U'\u2029';
char16_t c8 = U'\u8010';
char16_t c9 = L'a';
char16_t ca = L'\u2029';
char16_t cb = L'\u8010';






int main ()
{
    if (sizeof (u'a') != sizeof (char16_t))
 abort ();
    if (sizeof (u'\0') != sizeof (char16_t))
 abort ();
    if (sizeof (u'\u0024') != sizeof (char16_t))
 abort ();
    if (sizeof (u'\u2029') != sizeof (char16_t))
 abort ();
    if (sizeof (u'\u8010') != sizeof (char16_t))
 abort ();

    if (c0 != 0x0061)
 abort ();
    if (c1 != 0x0000)
 abort ();
    if (c2 != 0x0024)
 abort ();
    if (c3 != 0x2029)
 abort ();
    if (c4 != 0x8010)
 abort ();

    if (c5 != 0x0061)
 abort ();
    if (c6 != 0x0061)
 abort ();
    if (c7 != 0x2029)
 abort ();
    if (c8 != 0x8010)
 abort ();
    if (c9 != 0x0061)
 abort ();
    if (ca != 0x2029)
 abort ();
    if (cb != 0x8010)
 abort ();
}
