


int x;

int
f1 (int i, int j, int k)
{
  int *p = k ? &i : &j;
  i = 3;
  *p = 5;
  x = j;
}
