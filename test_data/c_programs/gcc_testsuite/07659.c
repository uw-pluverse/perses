

union U {
  int a;
  float b;
};
struct A {
  union U u1;
  char a[100];
};
void bar (struct A *);
void foo ()
  {
    {
      struct A a;
      bar (&a);
    }
    {
      struct A a;
      bar (&a);
    }
  }
