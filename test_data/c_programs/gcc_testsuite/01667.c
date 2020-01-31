double fabs(double);

void test_coms(void);

extern void abort(void);

struct {double r, s; } com;
double single;
long int mycom;
long long int mycom2;
struct {int i, j; } f03_com2;

int main(int argc, char **argv)
{
  com.r = 1.0;
  com.s = 2.0;
  single = 1.0;
  mycom = 1;
  mycom2 = 2;
  f03_com2.i = 1;
  f03_com2.j = 2;


  test_coms();

  if(fabs(com.r - 1.1) > 0.00000000)
    abort();
  if(fabs(com.s - 2.1) > 0.00000000)
    abort();
  if(fabs(single - 1.1) > 0.00000000)
    abort();
  if(mycom != 2)
    abort();
  if(mycom2 != 3)
    abort();
  if(f03_com2.i != 2)
    abort();
  if(f03_com2.j != 3)
    abort();

  return 0;
}
