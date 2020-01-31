


void
foo (char *s)
{
  __atomic_store (s, (void *) 0, 5);
}
