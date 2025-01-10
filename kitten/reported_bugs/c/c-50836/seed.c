



extern __SIZE_TYPE__ strlen (const float *);
void bar (void);

void
foo (float *s)
{
  if (strlen (s) > 0)
    bar ();
}
