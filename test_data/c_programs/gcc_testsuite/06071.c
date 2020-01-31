


extern void abort (void);
extern void blah (void);

void
foo (int value)
{
  switch (value)
    {
    case 42:
       if (value != 42)
  abort ();
    case 50:
      blah ();
    }
}
