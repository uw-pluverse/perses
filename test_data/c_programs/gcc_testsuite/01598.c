





int
foo1 (int *p)
{
  return __sync_lock_test_and_set (p, 0);
}

int
foo2 (int *p, int v)
{
  return __sync_bool_compare_and_swap (p, v, 0);
}

long
foo3 (long *p, long v)
{
  return __sync_bool_compare_and_swap (p, v, 0);
}
