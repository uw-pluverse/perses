

void
volarr_cpy(char *d, volatile char *s)
{
  int i;

  for (i = 0; i < 16; i++)
    d[i] = s[i];
}
