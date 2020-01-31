






int
main (void)
{
  (*(volatile unsigned char*)0xFFFFC9) = (*(volatile unsigned char*)0xFFFDC8) & ~0x01;
  (*(volatile unsigned char*)0xFFFFC9) = (*(volatile unsigned char*)0xFFFDC8) ^ ~0xFE;
  (*(volatile unsigned char*)0xFFFFC9) = (*(volatile unsigned char*)0xFFFDC8) | ~0xFE;
  return 0;
}
