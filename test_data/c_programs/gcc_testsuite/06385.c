


static inline long unsigned int
func1(const volatile void * base, long unsigned int byteOffset)
{
  volatile long unsigned int *addr
    = (volatile long unsigned int *)((long unsigned int)base + byteOffset);
  return *addr;
}

static inline long unsigned int
func2(long unsigned int data)
{
    return func1(&data, 0);
}

int main(int argc, char *argv[]) {
  long unsigned int b = func2(argc);

  return 0;
}
