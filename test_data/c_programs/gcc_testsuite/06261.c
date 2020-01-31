





typedef unsigned short char16_t;
typedef unsigned int char32_t;

extern void abort (void);

int main ()
{
    if (sizeof (char16_t) != sizeof (u'a'))
 abort();
    if (sizeof (char32_t) != sizeof (U'a'))
 abort();
}
