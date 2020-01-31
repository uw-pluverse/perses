


int t() __attribute__ ((const));
void
q()
{
  int i = t();
  if (!i)
    i = t();
}
