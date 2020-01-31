



extern int e;



int
fn (void)
{
  if ((e ? 4 : 8) <= (e ? 4 : 8))
    return 1;
  return 0;
}
