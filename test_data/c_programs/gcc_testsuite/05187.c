


struct a {int a,b;};
const static struct a a;
static int b[10];
int c;
int
test()
{
  return a.a+b[c];
}
