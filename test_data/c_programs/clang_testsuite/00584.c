typedef struct nested1 {
    int a1;
    int b1;
} NESTED1;
struct nested2 {
    int a;
    NESTED1;
    int b;
};
struct test {
    int x;
    struct nested2;
    int y;
};
void foo()
{
  struct test var;
  var.a;
  var.b;
  var.a1;
  var.b1;
  var.x;
  var.y;
}
void foo2(struct test* var)
{
  var->a;
  var->b;
  var->a1;
  var->b1;
  var->x;
  var->y;
}
