void func()
{
   const int *arr;
   arr[0] = 1;
}
struct foo {
  int bar;
};
struct foo sfoo = { 0 };
int func2()
{
  const struct foo *fp;
  fp = &sfoo;
  fp[0].bar = 1;
  return sfoo.bar;
}
