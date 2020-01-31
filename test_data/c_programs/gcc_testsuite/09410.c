


void abort (void);

int x[500][500];
int y[500];
int g_sum=0;

__attribute__((noinline))
void init (int i, int j)
{
  x[i][j]=1;
}

__attribute__((noinline))
void parloop (int N)
{
  int i, j;
  int sum;


  sum=0;
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
      y[i]+=x[i][j];
    sum += y[i];
  }
  g_sum = sum;
}

int main(void)
{
  int i,j;
  for (i = 0; i < 500; i++)
    for (j = 0; j < 500; j++)
      init(i, j);

  parloop(500);

  return 0;
}
