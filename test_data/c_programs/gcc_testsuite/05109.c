

extern void g(void);

void
f (unsigned n)
{
  unsigned k;
  for(k = 0;k <= n;k++)
    g();

  for(k = 0;k <= n;k += 4)
    g();






  for(k = 5;k <= n;k += 5)
    g();


  for(k = 4;k <= n;k += 5)
    g();

  for(k = 15;k >= n;k--)
    g();
}
