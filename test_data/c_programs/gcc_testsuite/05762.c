

int *t;
int g(int);
int f(int tt)
{
    int *t1 = t;
    if (*t1)
      *t1 = 2;
    return g(*t1);
}
