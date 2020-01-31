





union foo
{
  int i;
  long l;
};

void
testfunc ()
{

  static union foo f1 = { 0 };
  static union foo f2 = { 1 };


  static union foo f3 = { 0 };
  static union foo f4 = { 1 };
}
