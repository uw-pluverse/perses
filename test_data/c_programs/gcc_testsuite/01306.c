






float __attribute__((aligned(16))) input[32];
float __attribute__((aligned(16))) output[32];

void
foo ()
{
  int i = 0;

  for (i = 0; i < 32; i++)
    output[i] = __builtin_roundf (input[i]);
}
