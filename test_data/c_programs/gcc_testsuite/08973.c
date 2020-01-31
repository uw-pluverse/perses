


unsigned int f()
{
  static const char string[] __attribute__((aligned(sizeof(int)))) = "Private";

  unsigned int priv;
  __builtin_memcpy(&priv, &string[0], sizeof(priv));
  return priv;
}
