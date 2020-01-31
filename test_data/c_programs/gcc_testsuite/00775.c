


long v = 0;

long
atomic_fetch_add_RELAXED (long a)
{
  return __atomic_fetch_add (&v, a, 0);
}

long
atomic_fetch_sub_RELAXED (long a)
{
  return __atomic_fetch_sub (&v, a, 0);
}

long
atomic_fetch_and_RELAXED (long a)
{
  return __atomic_fetch_and (&v, a, 0);
}

long
atomic_fetch_nand_RELAXED (long a)
{
  return __atomic_fetch_nand (&v, a, 0);
}

long
atomic_fetch_xor_RELAXED (long a)
{
  return __atomic_fetch_xor (&v, a, 0);
}

long
atomic_fetch_or_RELAXED (long a)
{
  return __atomic_fetch_or (&v, a, 0);
}
