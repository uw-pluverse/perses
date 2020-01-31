




double d[65536], e[65536];

void
foo (void)
{
  int i;
  double f, g;
  for (i = 0; i < 65536; i++)
    {
      f = e[i];
      goto lab1;
    lab2:
      d[i] = f * g;
      continue;
    lab1:
      g = d[i];
      goto lab2;
    }
}
