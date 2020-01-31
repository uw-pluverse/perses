

int foo (int);

volatile unsigned char g;

void bar (int p)
{
  char l = 0xE1;
  func ((foo ((p & g) <= l), 1));
}
