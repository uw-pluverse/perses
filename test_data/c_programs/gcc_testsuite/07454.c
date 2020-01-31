




struct mem
{
  float avg;
  int len;
};

float method2_int16 (struct mem *mem)
{
  int i;
  float avg;

  for (i = 0; i < 100; ++i)
     avg += mem[i].avg * (float) mem[i].len;

  return avg;
}
