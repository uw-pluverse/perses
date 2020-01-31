
int x;
volatile unsigned int y;
void __attribute__ ((interrupt_handler)) f1 (void)
{
  x = y + 11;
}

void __attribute__ ((interrupt_handler)) f2 (void)
{
  unsigned int x00 = y; unsigned int x01 = y; unsigned int x02 = y; unsigned int x03 = y; unsigned int x04 = y; unsigned int x05 = y; unsigned int x06 = y; unsigned int x07 = y; unsigned int x08 = y; unsigned int x09 = y; unsigned int x10 = y; unsigned int x11 = y; unsigned int x12 = y; unsigned int x13 = y; unsigned int x14 = y; unsigned int x15 = y; unsigned int x16 = y; unsigned int x17 = y; unsigned int x18 = y; unsigned int x19 = y; unsigned int x20 = y; unsigned int x21 = y; unsigned int x22 = y; unsigned int x23 = y; unsigned int x24 = y; unsigned int x25 = y; unsigned int x26 = y; unsigned int x27 = y; unsigned int x28 = y; unsigned int x29 = y;
  y = x00; y = x01; y = x02; y = x03; y = x04; y = x05; y = x06; y = x07; y = x08; y = x09; y = x10; y = x11; y = x12; y = x13; y = x14; y = x15; y = x16; y = x17; y = x18; y = x19; y = x20; y = x21; y = x22; y = x23; y = x24; y = x25; y = x26; y = x27; y = x28; y = x29;
}
