



signed char sc;
unsigned char uc;
short int ss;
unsigned short int us;
int si;
unsigned int ui;

void test1 (void)
{
  int a = uc & 0xff;
  int b = sc & 0x7f;
  int c = 0xff & uc;
  int d = 0x7f & sc;
  int e = uc & sc;
  unsigned char f = (int) uc;
  signed char g = (int) sc;
  unsigned char h = (unsigned int) (short int) uc;
  signed char i = (int) (unsigned short int) sc;
  unsigned char j = (unsigned int) (short int) us;
  signed char k = (int) (unsigned short int) ss;
}

void test2 (void)
{
  signed char a = (unsigned char) sc;
  unsigned char b = (signed char) uc;
  signed char c = (int) (unsigned char) sc;
  unsigned char d = (int) (signed char) uc;
  int e = (unsigned int) si;
  unsigned int f = (int) ui;
}
