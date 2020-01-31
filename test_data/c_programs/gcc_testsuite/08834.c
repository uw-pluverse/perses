




int main()
{
  const char *s = "8" "8";
  if (s[0] != '8' || s[1] != '8')
    __builtin_abort ();
  return 0;
}
