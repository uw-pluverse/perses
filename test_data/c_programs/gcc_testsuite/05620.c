




int g(void);
int h(void);
int f(int *i, int *j)
{
  while (1)
    {
      if (*i > *j || *i == *j)
        break;
      return g();
    }
  return h();
}
