static inline void break_optimization(void *arg) {
  __asm__ __volatile__("" : : "r" (arg) : "memory");
}
int main(int argc, char **argv)
{
  int i;
  char buffer[128];
  for (i = 0; argv[0][i] && i < sizeof (buffer) - 1; ++i)
    buffer[i] = argv[0][i];
  buffer[i] = '\0';
  break_optimization(buffer);
  for (i = 0; argv[0][i] && i < sizeof (buffer) - 1; ++i)
    if (buffer[i] != argv[0][i])
      return 1;
  return 0;
}
