


int f(int i, int j)
{
    int b[2][2];
    if (&b[1][i] == &b[0][j])
      return 1;
    return 0;
}
