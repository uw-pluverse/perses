struct foo;
struct foo a();
void b(struct foo);
void c();
void func(void *p) {
  a();
  b(*(struct foo*)p);
  c(*(struct foo*)p);
}
