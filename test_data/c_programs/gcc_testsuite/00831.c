






int
bar (int a)
{
  return a - 6;
}

__attribute__ ((target ("tune=cortex-a53")))
int
bam (int a)
{
  return a - bar (a);
}
