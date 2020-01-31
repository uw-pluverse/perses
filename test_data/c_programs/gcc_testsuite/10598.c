



void abort (void);

struct A
{
  int i[100];
};

struct A a1;

struct A f ()
{
  struct A a2;
  a2.i[0] = 42;

  if (a1.i[0] != 0)
    abort ();
  return a2;
}

int main()
{
  a1 = f();
  return 0;
}
