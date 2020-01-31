signed long long sa[1024] __attribute__((__aligned__(32)));
signed long long sb[1024] __attribute__((__aligned__(32)));
signed long long sc[1024] __attribute__((__aligned__(32)));

unsigned long long ua[1024] __attribute__((__aligned__(32)));
unsigned long long ub[1024] __attribute__((__aligned__(32)));
unsigned long long uc[1024] __attribute__((__aligned__(32)));

void
sign_add (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    sa[i] = sb[i] + sc[i];
}

void
sign_sub (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    sa[i] = sb[i] - sc[i];
}

void
sign_shift_left (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    sa[i] = sb[i] << sc[i];
}

void
sign_shift_right (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    sa[i] = sb[i] >> sc[i];
}

void
sign_max (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    sa[i] = (sb[i] > sc[i]) ? sb[i] : sc[i];
}

void
sign_min (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    sa[i] = (sb[i] < sc[i]) ? sb[i] : sc[i];
}

void
sign_abs (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    sa[i] = (sb[i] < 0) ? -sb[i] : sb[i];
}

void
sign_eq (signed long long val1, signed long long val2)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    sa[i] = (sb[i] == sc[i]) ? val1 : val2;
}

void
sign_lt (signed long long val1, signed long long val2)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    sa[i] = (sb[i] < sc[i]) ? val1 : val2;
}

void
uns_add (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    ua[i] = ub[i] + uc[i];
}

void
uns_sub (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    ua[i] = ub[i] - uc[i];
}

void
uns_shift_left (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    ua[i] = ub[i] << uc[i];
}

void
uns_shift_right (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    ua[i] = ub[i] >> uc[i];
}

void
uns_max (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    ua[i] = (ub[i] > uc[i]) ? ub[i] : uc[i];
}

void
uns_min (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    ua[i] = (ub[i] < uc[i]) ? ub[i] : uc[i];
}

void
uns_eq (unsigned long long val1, unsigned long long val2)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    ua[i] = (ub[i] == uc[i]) ? val1 : val2;
}

void
uns_lt (unsigned long long val1, unsigned long long val2)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    ua[i] = (ub[i] < uc[i]) ? val1 : val2;
}
