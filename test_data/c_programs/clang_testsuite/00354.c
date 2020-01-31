int a(int x)
{
  int (*y)[x];
  return sizeof(*(puts("asdf"),y));
}
int b() {
  return sizeof(*(char(*)[puts("asdf")])0);
}
int c() {
  static int (*y)[puts("asdf")];
  return sizeof(*y);
}
