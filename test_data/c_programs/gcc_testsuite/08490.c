




extern int a, b;
long c[1][1][1];
long d[1][1];

void fn1 ()
{
  for (int e = 0; e < b; e = e + 1)
    *(e + **c) = (a && *d[1]) - 1;
}
