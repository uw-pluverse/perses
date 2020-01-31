


void bla(void);

void
foo(int c, int d)
{
  goto skip;

ebef:
  goto xxx;

skip:

  if (c)
    {
xxx:;
    if (!c)
      bla ();
    }

  if (d)
    goto ebef;
}
