


double test1 (double i, double j)
{
  if (i >= j)
    if (i <= j)
      goto plif;
    else
      goto plouf;
  else
    goto plif;

plif:
  return 0;
plouf:
  return -1;
}
