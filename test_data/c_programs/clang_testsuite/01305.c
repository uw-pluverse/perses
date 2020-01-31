__attribute__((noinline))
void fct(volatile int *buffer)
{
  memset(buffer - 1, 0, 7 * sizeof(int));
}
int main(int argc, char **argv)
{
  int prebuf[7];
  int value1 = 42;
  int buffer[5];
  int value2 = 42;
  int postbuf[7];
  fct(prebuf + 1);
  fct(postbuf + 1);
  fct(buffer);
  return value1 != 42 || value2 != 42;
}
