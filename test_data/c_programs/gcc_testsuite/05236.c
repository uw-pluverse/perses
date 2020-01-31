






typedef int arr_2[50][50];

void foo (arr_2 a2, int v1)
{
  int i, j;

  i = v1 + 5;
  j = i;
  a2 [i-10] [j] = 2;
  a2 [i] [j++] = i;
  a2 [i+20] [j++] = i;
  a2 [i-3] [i-1] += 1;
  return;
}
