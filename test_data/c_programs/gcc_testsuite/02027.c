int b = 0;

func () { }

void
testit(int x)
{
  if (x != 20)
    abort ();
}

int
main()

{
  int a = 0;

  if (b)
    func();



  testit ((a + 23) & 0xfffffffc);
  exit (0);
}
