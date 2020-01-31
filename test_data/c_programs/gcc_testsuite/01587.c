unsigned int
and_peep2_hi (unsigned int y, unsigned int *x)
{
  *x = y & 0x7ff;
  return y;
}

unsigned int
and_peep2_qi (unsigned int y, unsigned int *x)
{
  *x = y & 0x5f;
  return y;
}


unsigned int
and_peep2_q (unsigned int y, unsigned int *x)
{
  *x = y & 0xfe;
  return y;
}
