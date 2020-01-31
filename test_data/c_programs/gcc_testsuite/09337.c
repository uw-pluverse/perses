


extern void func();

void test1(char *signature)
{
  char ch = signature[0];
  if (ch == 15 || ch == 3)
  {
    if (ch == 15) func();
  }
}


void test2(char *signature)
{
  char ch = signature[0];
  if (ch == 15 || ch == 3)
  {
    if (ch > 14) func();
  }
}
