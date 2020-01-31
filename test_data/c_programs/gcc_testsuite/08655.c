


void f1()
{
}

void f2()
{
}

static void (*a)(void)=&f1;
static void (*b)(void)=&f1;
static void (*c)(void)=&f2;
static void (*d)(void)=&f2;

int main()
{
  a();
  b();
  c();
  d();

  return 0;
}
