




extern int A[], B[];

int
foo (int x, int c, int i)
{
  if (A[i] && B[i])
    x = x % ((c & 4) ? 8 : 4);
  return x;
}
