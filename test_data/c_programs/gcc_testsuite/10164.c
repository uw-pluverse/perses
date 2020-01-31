






struct T { int i; };
struct S { struct T t; };
static struct S s = (struct S) { .t = { 42 } };
