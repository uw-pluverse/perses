







struct ia64_fdesc
{
  unsigned long func;
  unsigned long gp;
};

void
os_boot_rendez (void)
{
}

extern int check (unsigned long);

int
main (int argc, char **argv)
{
  int i;
  int res = 0;

  for (i = 0; i < 1; i++)
    res += check (((struct ia64_fdesc *) os_boot_rendez)->gp);
  return res;
}
