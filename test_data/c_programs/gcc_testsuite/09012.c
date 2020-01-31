






int foo (int);

int
bar (int a, int b, int c)
{
  foo (a + b << c);
  foo ((a + b) << c);
  foo (a + (b << c));
  foo (1 + 2 << c);
  foo ((1 + 2) << c);
  foo (1 + (2 << c));
  foo (1 + 2 << 3);
  foo ((1 + 2) << 3);
  foo (1 + (2 << 3));
  foo (a << b + c);
  foo ((a << b) + c);
  foo (a << (b + c));
  foo (1 << 2 + c);
  foo ((1 << 2) + c);
  foo (1 << (2 + c));
  foo (1 << 2 + 3);
  foo ((1 << 2) + 3);
  foo (1 << (2 + 3));
  foo (a + b >> c);
  foo ((a + b) >> c);
  foo (a + (b >> c));
  foo (1 + 2 >> c);
  foo ((1 + 2) >> c);
  foo (1 + (2 >> c));
  foo (1 + 2 >> 3);
  foo ((1 + 2) >> 3);
  foo (1 + (2 >> 3));
  foo (a >> b + c);
  foo ((a >> b) + c);
  foo (a >> (b + c));
  foo (1 >> 2 + c);
  foo ((1 >> 2) + c);
  foo (1 >> (2 + c));
  foo (1 >> 2 + 3);
  foo ((1 >> 2) + 3);
  foo (1 >> (2 + 3));
  foo (a - b << c);
  foo ((a - b) << c);
  foo (a - (b << c));
  foo (6 - 5 << c);
  foo ((6 - 5) << c);
  foo (6 - (5 << c));
  foo (6 - 5 << 4);
  foo ((6 - 5) << 4);
  foo (6 - (5 << 4));
  foo (a << b - c);
  foo ((a << b) - c);
  foo (a << (b - c));
  foo (6 << 5 - c);
  foo ((6 << 5) - c);
  foo (6 << (5 - c));
  foo (6 << 5 - 4);
  foo ((6 << 5) - 4);
  foo (6 << (5 - 4));
  foo (a - b >> c);
  foo ((a - b) >> c);
  foo (a - (b >> c));
  foo (6 - 5 >> c);
  foo ((6 - 5) >> c);
  foo (6 - (5 >> c));
  foo (6 - 5 >> 4);
  foo ((6 - 5) >> 4);
  foo (6 - (5 >> 4));
  foo (a >> b - c);
  foo ((a >> b) - c);
  foo (a >> (b - c));
  foo (6 >> 5 - c);
  foo ((6 >> 5) - c);
  foo (6 >> (5 - c));
  foo (6 >> 5 - 4);
  foo ((6 >> 5) - 4);
  foo (6 >> (5 - 4));
}
