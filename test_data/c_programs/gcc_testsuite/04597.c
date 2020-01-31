



extern int tab[16];

void
execute (int *ip, int x)
{
  int *xp = tab;
base:
  if (x)
    return;
  *xp++ = *ip;
  goto *(&&base + *ip);
}
