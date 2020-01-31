




extern int i;
void
f (int c)
{
  switch (c)
    {
    case (1 ? 1 : i):
      ;
    }
}
