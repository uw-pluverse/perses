




void
matrix_mul (unsigned char *in, unsigned char *out, int size)
{
  int i;
  for (i = 0; i < size; i++)
    {
      out[0] = in[0] + in[1] + in[3];
      out[1] = in[0] + in[2] + in[4];
      out[2] = in[1] + in[2] + in[4];
      in += 4;
      out += 3;
    }
}
