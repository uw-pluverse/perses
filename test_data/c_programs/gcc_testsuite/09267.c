




enum { A = 1 << (sizeof (int) * 8 - 1) };
int k = 1 << (sizeof (int) * 8 - 1);

void
fn (int i)
{
  switch (i)
  case 1 << (sizeof (int) * 8 - 1): break;
}
