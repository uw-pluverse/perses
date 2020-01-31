


enum e { FIRST, LAST };

extern void f2 (enum e);

void
f1 ()
{
  enum e v;

  for (v = FIRST; v < LAST; ++v)
    f2 (v);
  for (v = FIRST; v < LAST; v++)
    f2 (v);
  for (v = LAST; v > FIRST; --v)
    f2 (v);
  for (v = LAST; v > FIRST; v--)
    f2 (v);
}
