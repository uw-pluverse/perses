






void fsc (signed char sc);
void fuc (unsigned char uc);
unsigned fui (unsigned int ui);
void fsi (signed int ui);

void h (int x)
{
  unsigned int ui = 3;
  int si = 3;
  unsigned char uc = 3;
  signed char sc = 3;

  uc = ui;
  uc = si;
  sc = ui;
  sc = si;
  fuc (ui);
  fuc (si);
  fsc (ui);
  fsc (si);

  fsi (si);
  fui (ui);
  fsi (uc);
  si = uc;
  fui (uc);
  ui = uc;
  fui ('A');
  ui = 'A';
  fsi ('A');
  si = 'A';
  fuc ('A');
  uc = 'A';

  uc = x ? 1U : -1;
  uc = x ? (-127 -1) : 1U;
  uc = x ? 1 : -1;
  uc = x ? (-127 -1) : 1;
  ui = x ? 1U : -1;
  ui = x ? (-2147483647 -1) : 1U;
  ui = ui ? (-127 -1) : 1U;
  ui = 1U * -1;
  ui = ui + (-2147483647 -1);
  ui = x ? 1 : -1;
  ui = ui ? (-127 -1) : 1;

  fuc (-1);
  uc = -1;
  fui (-1);
  ui = -1;
  fuc ('\xa0');
  uc = '\xa0';
  fui ('\xa0');
  ui = '\xa0';
  fsi ((unsigned) 2147483647 + 1U);
  si = (unsigned) 2147483647 + 1U;


  fsi ((2147483647 *2U +1U) - 1);
  si = (2147483647 *2U +1U) - 1;
  fsi ((2147483647 *2U +1U) - 1U);
  si = (2147483647 *2U +1U) - 1U;
  fsi ((2147483647 *2U +1U)/3U);
  si = (2147483647 *2U +1U)/3U;
  fsi ((2147483647 *2U +1U)/3);
  si = (2147483647 *2U +1U)/3;
  fui ((2147483647 *2U +1U) - 1);
  ui = (2147483647 *2U +1U) - 1;

  uc = (unsigned char) -1;
  ui = -1 * (1 * -1);
  ui = (unsigned) -1;

  fsc (uc);
  sc = uc;
  fuc (sc);
  uc = sc;
  fsi (ui);
  si = ui;
  fui (si);
  ui = si;
  fui (sc);
  ui = sc;
}

unsigned fui (unsigned a) { return a + -1; }
