


void aa (void);
void aos (void);
void aob (void);

void
blah (int code1, int code2)
{
  int i;
  int n_sets;

  n_sets = (int) (code1 == 32);
  if (code2 == 64) goto L2; else goto L3;

L2:
  aa ();

L3:
  if (n_sets > 1) goto L4; else goto L10;

L4:
  aos ();
  i = 0;
  goto L24;

L10:
  if (n_sets > 0) goto L25; else goto L8;

L25:
  i = 0;

L24:
  aob ();
  i = i + 1;
  if (i < n_sets) goto L24; else goto L8;

L8:
  return;
}
