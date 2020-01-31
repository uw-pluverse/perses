





void
foo (float *output, float *input)
{
  int i = 0;

  for (i = 0; i < 32; i++)
    output[i] = __builtin_truncf (input[i]);
}
