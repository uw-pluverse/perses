


void foo (void);

void
bar (int i, int partial, int args_addr)
{
  int offset = 0;
  if (args_addr == 0)
    offset = 0;
  if (i >= offset)
    foo ();
}
