


extern int a;
extern int *p;

void test (void);

int main ()
{
  *p = 0;
  a = 1;
  test ();
  return 0;
}
