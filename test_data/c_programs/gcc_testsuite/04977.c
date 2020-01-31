




int argc = 1;





int func (int *p, int *q) {
    int x = 0;
 for (int ii = 0; ii < 1000; ii++) {
 x += (q[ii] + p[ii]);
    }
    return x;

}

int main ()
{
  int ii = 0, x;
  int Array[1000], Array2[1000];

  for (ii = 0; ii < 1000; ii++)
    {
      Array[ii] = 5 + argc;
      Array2[ii] = argc;
    }
  x = func (Array, Array2);

  if (x != 1000 * 7)
    return 1;
  return 0;
}
