

int t[2];
int g(int);
int f(int tt)
{
    if (t[0])
      t[0] = 2;
    return g(t[0]);
}
