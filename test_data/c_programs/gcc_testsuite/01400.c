





void foo (int ilast,float* w, float* w2)
{
  int i;
  for (i = 0; i < ilast; ++i)
  {
    w[i] = (0.0f > w2[i] ? 0.0f : w2[i]);
  }
}
