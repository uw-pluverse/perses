







extern void abort (void);

int stack_pointer;

void
__attribute__((noinline))
mystop ()
{
  abort ();
}

void
__attribute__((noinline))
add ()
{
  if (stack_pointer + 1 > 10)
    mystop ();

  stack_pointer = stack_pointer + 1;
}

int main ()
{
  add ();
  return stack_pointer - 1;
}
