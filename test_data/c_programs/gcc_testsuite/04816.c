

int
foo ()
{
  return __sync_fetch_and_add ((int *) 0, 1);
}
