



void noret (void) __attribute__ ((noreturn));
int bar (void);
void baz (const char *);
static int v = -1;

void
foo (void)
{
  if (bar () && v == -1)
    {
      baz ("baz");
      noret ();
    }
  noret ();
}
