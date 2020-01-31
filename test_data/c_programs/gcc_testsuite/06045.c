


int abarney[2];
int afred[1];

void foo(int edx, int eax)
{
  if (eax == 100)
    {
      if (edx == 1)
        {
          abarney[0] = 5;
          abarney[1] = 6;
        }
    }
  if (eax == 100)
    {
      if (-- edx == 0)
        afred[0] = 2;
    }
}
