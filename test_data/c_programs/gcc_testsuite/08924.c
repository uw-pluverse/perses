



struct T { int i; };
struct S { struct T t; };
struct S s = { .t = { (int) { 1 } } };
