





void f()
{
  int size = 40;
  char *memory = __builtin_alloca(size);
  __builtin___clear_cache(memory, memory + size);
}
