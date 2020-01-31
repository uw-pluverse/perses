





__attribute__ ((target ("strict-align")))
int
bar (int a)
{
  return a - 6;
}

int
bam (int a)
{
  return a - bar (a);
}
