


void abort (void);

void parloop (int N)
{
  int i;
  int x[10000990];

  for (i = 0; i < N; i++)
    x[i] = i + 3;

  for (i = 0; i < N; i++)
    {
      if (x[i] != i + 3)
 abort ();
    }
}

int main(void)
{
  parloop(10000);

  return 0;
}
