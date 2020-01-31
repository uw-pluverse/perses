






float
fixed_to_float (int i)
{
  return ((float) i / (1 << 16));
}

int
float_to_fixed (float f)
{
  return ((int) (f * (1 << 16)));
}
