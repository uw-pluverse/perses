



int get_int(const void *p)
{
  int w;
  __builtin_memcpy(&w, p, sizeof (int));
  return w;
}
