




void
foo (int *p, int a)
{
  __atomic_fetch_add (&p, a, 0);
  __atomic_add_fetch (&p, a, 0);
}
