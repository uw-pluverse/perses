int main()
{
  long double d;
  char s[sizeof d];

  __builtin_memcpy(&d, "AAAAAAAAAAAAAAA", sizeof d);
  __builtin_memcpy(&s, &d, sizeof s);

  if (__builtin_strncmp (s, "AAAAAAAAAAAAAAA", sizeof s) != 0)
    __builtin_abort ();

  return 0;
}
