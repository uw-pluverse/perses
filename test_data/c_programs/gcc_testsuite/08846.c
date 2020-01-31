




#pragma GCC diagnostic ignored "-Waddress"

void grill ();
void __attribute__((dj)) bar() { }

int i;

void
foo ()
{
  if (&i)
    grill ();
}
