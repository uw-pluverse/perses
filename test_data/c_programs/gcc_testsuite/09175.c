



struct unsigned_bit {
  unsigned int x:1;
} unsigned_bit;
struct signed_bit {
  int x:1;
} signed_bit;
int bar;
int bar2;

void func1()
{


  unsigned_bit.x = (bar != 0);
  unsigned_bit.x = (bar == 0);
  unsigned_bit.x = (bar <= 0);
  unsigned_bit.x = (bar >= 0);
  unsigned_bit.x = (bar < 0);
  unsigned_bit.x = (bar > 0);
  unsigned_bit.x = !bar;
  unsigned_bit.x = (bar || bar2);
  unsigned_bit.x = (bar && bar2);


  unsigned_bit.x = bar != 0 ? 1 : 0;
  unsigned_bit.x = bar != 0 ? 1.0 : 0.0;



  unsigned_bit.x = bar != 0 ? 2 : 0;
  unsigned_bit.x = bar != 0 ? 0 : -1;
}

void func2()
{
  signed char schar_x;


  schar_x = bar != 0 ? 1 : 0;
  schar_x = bar != 0 ? 2.0 : 10;



  schar_x = bar != 0 ? 2.1 : 10;
  schar_x = bar != 0 ? (signed char) 1024: -1024;
}



void func3()
{
  unsigned char uchar_x;


  uchar_x = bar != 0 ? 1 : 0;
  uchar_x = bar != 0 ? 2.0 : 10;



  uchar_x = bar != 0 ? 2.1 : 10;
  uchar_x = bar != 0
    ? (unsigned char) 1024
    : -1;
}

void func4()
{
  signed_bit.x = -1;
  signed_bit.x = bar != 0 ? -1.0 : 0.0;
  signed_bit.x = bar != 0 ? -1 : 0;


  signed_bit.x = 1;
  signed_bit.x = (bar != 0);
  signed_bit.x = (bar == 0);
  signed_bit.x = (bar <= 0);
  signed_bit.x = (bar >= 0);
  signed_bit.x = (bar < 0);
  signed_bit.x = (bar > 0);
  signed_bit.x = !bar;
  signed_bit.x = (bar || bar2);
  signed_bit.x = (bar && bar2);
  signed_bit.x = bar != 0 ? 1 : 0;
  signed_bit.x = bar != 0 ? 2 : 0;
}
