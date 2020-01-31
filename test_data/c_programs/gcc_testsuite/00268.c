







int
calc (int j)
{
  if (j<=1) return 1;
  return calc(j-1)*(j+1);
}
