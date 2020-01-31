const int AA = 5;
int f1(enum {AA,BB} E) {
    return BB;
}
int f2(enum {AA=7,BB} E) {
    return AA;
}
int f(void (*g)(), enum {AA,BB} h) {
    return AA;
}
int pr31366(struct { enum { a = 1 } b; } c) {
  return a;
}
