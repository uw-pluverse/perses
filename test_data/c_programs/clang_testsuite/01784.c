int g(int x);
void h(int x);
int f(int x)
{
out_err:
  if (g(x)) {
    h(x);
  }
  goto out_err;
}
