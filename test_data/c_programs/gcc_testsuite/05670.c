struct bla
{
  char x[187];
  int y;
  char z[253];
} arr_base[100];

void xxx(void)
{
  int iter;

  for (iter = 0; iter < 100; iter++)
    arr_base[iter].y = 17 * iter;
}
