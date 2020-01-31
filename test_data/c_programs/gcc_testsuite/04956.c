



unsigned char uc;
signed char sc;
unsigned short us;
signed short ss;
unsigned int u;
int i;

void
foo (void)
{
  __builtin_printf ("%u\n", uc);
  __builtin_printf ("%u\n", sc);
  __builtin_printf ("%u\n", us);
  __builtin_printf ("%u\n", ss);
  __builtin_printf ("%u\n", u);
  __builtin_printf ("%u\n", i);
}
