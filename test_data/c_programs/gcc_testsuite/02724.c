





int *bad_addr[65];
int arr_used;



void
init_addrs (void)
{
  int i;
  int bits_per_ptr = sizeof (void *) * 8;
  for (i = 0; i < bits_per_ptr; i++)
    bad_addr[i] = (void *)(1UL << i);
  arr_used = bits_per_ptr + 1;
}

void
prefetch_for_read (void)
{
  int i;
  for (i = 0; i < 65; i++)
    __builtin_prefetch (bad_addr[i], 0, 0);
}

void
prefetch_for_write (void)
{
  int i;
  for (i = 0; i < 65; i++)
    __builtin_prefetch (bad_addr[i], 1, 0);
}

int
main ()
{
  init_addrs ();
  prefetch_for_read ();
  prefetch_for_write ();
  exit (0);
}
