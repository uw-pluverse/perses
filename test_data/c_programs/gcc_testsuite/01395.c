


void *v;
void a (void *x) { }
void b (void) { }

int
main (int argc)
{
  if (argc == 12345)
    {
      a (v);
      return 1;
    }
  b ();

  return 0;
}
