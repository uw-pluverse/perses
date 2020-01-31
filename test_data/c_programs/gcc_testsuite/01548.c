


extern void abort ();

int main (int argc, char **argv)
{
  if (argc > 2)
    abort ();
  return 0;
}
