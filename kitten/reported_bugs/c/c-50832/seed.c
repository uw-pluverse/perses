


int
foo (int a)
{
  return __atomic_is_lock_free (2, a);
}

int
bar (int a)
{
  return __atomic_always_lock_free (2, a);
}
