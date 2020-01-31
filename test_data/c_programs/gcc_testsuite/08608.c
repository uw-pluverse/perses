


double floor (double);
double bar (double sum)
{
  int i;
  for (i = 0; i < 256; i++)
   sum += floor (0.5 + (i - 128));
  return sum;
}
