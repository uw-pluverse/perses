struct s
{
  int a;
};
int a[__builtin_offsetof(struct s, a) == 0];
