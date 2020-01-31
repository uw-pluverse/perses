


void destroy (void)
{
  __asm__ __volatile__ ("" : : : "memory");
}

void remove (void)
{
  __asm__ __volatile__ ("" : : : "memory");
}

void remove2 (void)
{
  __asm__ __volatile__ ("" : : : );
}

int main()
{
  destroy ();
  remove ();
  remove2 ();

  return 0;
}
