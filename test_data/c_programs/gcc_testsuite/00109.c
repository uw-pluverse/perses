


int abs (int);

void test (char* a, char* b)
{
  int i;
  for (i = 0; i < 10000; ++i)
    a[i] = abs (b[i]);
}
