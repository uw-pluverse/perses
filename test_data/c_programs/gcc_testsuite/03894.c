

void *
memcpy (void *a, const void *b, long unsigned int len)
{
  if (a == b)
    __builtin_abort ();
}
