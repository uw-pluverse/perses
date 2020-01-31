

struct S {
  int i;
};

struct S f(int i)
{
  return *(struct S *)&i;
}
