void f0(a, b, c, d) int a,b,c,d; {}
void t0(void) {
  f0(1);
}
void f1(a, b) int a, b; {}
void t1(void) {
  f1(1, 2, 3);
}
void f2(float);
void f2(x) float x; { }
typedef void (*f3)(void);
f3 t3(int b) { return b? f0 : f1; }
void f4() {
    char *rindex();
}
char *rindex(s, c)
     register char *s, c;
{
  return 0;
}
void proto(int);
void proto(x)
     int x;
{
}
void use_proto() {
  proto(42.1);
  (&proto)(42.1);
}
void func(short d) __attribute__((cdecl));
void __attribute__((cdecl)) func(d)
  short d;
{}
