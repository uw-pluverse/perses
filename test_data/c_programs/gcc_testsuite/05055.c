


void oof (const char *);
void foo (void);

static void
bar ()
{
  const char *label2 = (*"*.L_sfnames_b" == '*') + "*.L_sfnames_b";
  oof (label2);
}

void
ooof ()
{
  if (""[0] == 0)
    foo();
}
