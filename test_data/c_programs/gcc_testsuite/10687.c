


typedef struct foo {
 int x;
} foo_t;

extern struct foo x;

void f(void) {
  x.x = 0;
}
