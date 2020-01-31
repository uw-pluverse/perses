struct S {
  int *x;
  int y;
};
int *foo();
void test(struct S syz, int *pp) {
  int m = 0;
  syz.x = foo();
  struct S *ps = &syz;
  if (ps->x)
    m++;
  m += *syz.x;
}
void testTrackConstraintBRVisitorIsTrackingTurnedOn(struct S syz, int *pp) {
  int m = 0;
  syz.x = foo();
  struct S *ps = &syz;
  if (ps->x)
    m++;
  int *p = syz.x;
  m = *p;
}
