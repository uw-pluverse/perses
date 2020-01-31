




static struct {
  char buf[96 + 1];
} u1, u2;

extern void abort (void);

int main ()
{
  int i;
  char c;

  for (i = 0, c = 'A'; i < 96; i++, c++)
    {
      u1.buf[i] = 'a';
      if (c >= 'A' + 31)
 c = 'A';
      u2.buf[i] = c;
    }
  if (u1.buf[96] != '\0')
    abort ();

  return 0;
}
