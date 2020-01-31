



int fn1 (int x, int y)
{
 return x | ~(x | y);
}
int fn2 (int x, int y)
{
 return ~(x | y) | x;
}
int fn3 (int x, int y)
{
 return x | ~(y | x);
}
int fn4 (int x, int y)
{
 return ~(y | x) | x;
}
int fn5 (int z)
{
 return z | ~(z | 3);
}
int fn6 (int z)
{
 return ~(z | 3) | z;
}
