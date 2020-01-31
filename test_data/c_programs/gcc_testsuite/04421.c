



int bar(void);
void baz (void) __attribute__ ((noreturn));

void foo (void)
{
  while (bar ()) {
    switch (1) {
      default:
      baz ();
    }
  }
}
