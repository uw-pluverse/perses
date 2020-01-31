




extern int foo __attribute__((weak_import));

int main(void)
{
  if (&foo)
    return foo;
  return 0;
}
