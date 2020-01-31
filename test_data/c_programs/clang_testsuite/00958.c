static enum { foo, bar = 1U } z;
int main (void)
{
  int r = 0;
  if (bar - 2 < 0)
    r += 4;
  if (foo - 1 < 0)
    r += 2;
  if (z - 1 < 0)
    r++;
  return r;
}
