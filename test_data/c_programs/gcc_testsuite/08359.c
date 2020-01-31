




unsigned bmp_iter_set ();
int something (void);

void
bitmap_print_value_set (void)
{
  unsigned first;

  for (; bmp_iter_set (); )
    {
      if (!first)
 something ();
      first = 0;
    }
}
