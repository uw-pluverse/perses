





int
main()
{
  unsigned long long a = ~0;
  unsigned b = 0xa;

  __atomic_fetch_add (&a, b, 0);
  __atomic_fetch_and (&a, b, 0);
  __atomic_fetch_or (&a, b, 0);
  __atomic_fetch_xor (&a, b, 0);

  return a;
}
