
int main (void)
{
  void *x = ((void *)((unsigned int)2147483647 + 2));
  void *y = ((void *)((unsigned long)9223372036854775807L + 2));
  if (x >= ((void *)((unsigned int)2147483647 + 1))
      && x <= ((void *)((unsigned int)2147483647 + 6))
      && y >= ((void *)((unsigned long)9223372036854775807L + 1))
      && y <= ((void *)((unsigned long)9223372036854775807L + 6)))
    exit (0);
  else
    abort ();
}
