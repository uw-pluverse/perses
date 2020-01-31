



int
banana(long citron)
{
  switch (citron) {
    case 0x80000000:
    case 0x40000:
    case 0x40001:
      return 1;
      break;
  }
  return 0;
}
