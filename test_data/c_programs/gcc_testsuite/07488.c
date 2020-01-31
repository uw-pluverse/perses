




int out[128*4], out2[128], in[128*4];

void
foo ()
{
  int i, a0, a1, a2, a3;

  for (i = 0; i < 128; i++)
    {
      a0 = in[i*4];
      a1 = in[i*4 + 1];
      a2 = in[i*4 + 2];
      a3 = in[i*4 + 3];

      out[i*4] = a0;
      out[i*4 + 1] = a1;
      out[i*4 + 2] = a2;
      out[i*4 + 3] = a3;

      out2[i] = a0;
    }
}
