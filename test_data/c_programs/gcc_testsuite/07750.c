



extern void use (int);
void test (void)
{
  union
   {
     unsigned long ul;
     signed char sc;
   } u;

  u.sc = 8;
  u.sc &= 25;

  use (u.sc);
}
