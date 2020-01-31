


float dvec[256];

void test1 (float x)
{
  long i, j;
  for (i = 0; i < 256; ++i)
    for (j = 0; j < 131072; ++j)
      dvec[i] *= x;
}

void test2 (float x)
{
  long i, j;
  for (i = 0; i < 256; ++i)
    for (j = 0; j < 131072; ++j)
      dvec[i] *= 1.001f;
}
