



extern void abort();

struct A {
  long x;
};

struct R {
  struct A a, b;
};

struct R R = {
  {100}, {200}
};

void f(struct R r) {
  if (r.a.x != R.a.x || r.b.x != R.b.x)
    abort();
}

int main() {
  f(R);
  return 0;
}
