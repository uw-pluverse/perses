


void
leaf (void)
{
  int a = 0;
}

__attribute__ ((optimize("no-omit-frame-pointer")))
void
non_leaf_1 (void)
{
  leaf ();
}

__attribute__ ((optimize("no-omit-frame-pointer")))
void
non_leaf_2 (void)
{
  leaf ();
}
