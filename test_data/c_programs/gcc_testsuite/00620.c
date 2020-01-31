





static int
bar (int a)
{
  return a - 6;
}

__attribute__ ((target ("strict-align")))
int
bam (int a)
{
  return a - bar (a);
}
