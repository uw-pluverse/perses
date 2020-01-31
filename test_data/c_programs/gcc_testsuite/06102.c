


void
set_integer (void *dest, int value, int length)
{
  int tmp = value;
  __builtin_memcpy (dest, (void *) &tmp, length);
}
