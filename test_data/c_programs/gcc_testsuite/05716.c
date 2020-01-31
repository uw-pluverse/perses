


void bar (void);

void
foo (int a)
{
  switch (a)
    {
    case 4:
      if (a >= 3)
        if (a <= 5)
          bar ();
    }
}
