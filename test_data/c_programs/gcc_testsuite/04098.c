void foo (void);

void
bar ()
{
    unsigned len;

    for (len = 0; len < 2; len++)
 foo ();
}
