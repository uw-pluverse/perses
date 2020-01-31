




enum { A = 10 << (sizeof (int) * 8 - 2) };
int k = 10 << (sizeof (int) * 8 - 2);

void
fn (int i)
{
  switch (i)
  case 10 << (sizeof (int) * 8 - 2): break;
}
