


unsigned char c[0xFF];
void f(void)
{
  unsigned char i;
  c[128] = 128;
  i = 0;
  while (1)
  {

    if (((signed char) i) < 0) break;
    c[i] = ' ';
    i++;
  }
}
