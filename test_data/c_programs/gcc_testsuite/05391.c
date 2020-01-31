


int r[6];

void f (int n)
{
  while (-- n)
    {
      r [0] += r [5];
      r [1] += r [0];
      r [2] += r [1];
      r [3] += r [2];
      r [4] += r [3];
      r [5] += r [4];
    }
}
