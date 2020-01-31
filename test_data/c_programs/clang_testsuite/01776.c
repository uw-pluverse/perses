void idc(void *p) {
 if (p)
  ;
}
int test01(int *p) {
  if (p)
    ;
  return *p;
}
int test02(int *p, int *x) {
  if (p)
    ;
  idc(p);
 if (x)
  ;
  return *p;
}
int test03(int *p, int *x) {
 idc(p);
 if (p)
  ;
 return *p;
}
int deref04(int *p) {
  return *p;
}
int test04(int *p) {
  if (p)
    ;
  idc(p);
  return deref04(p);
}
int test11(int *q, int *x) {
 int *p = q;
 if (q)
  ;
 if (x)
  ;
 return *p;
}
int test12(int *q) {
 int *p = q;
 idc(q);
 return *p;
}
int test13(int *q) {
 int *p = q;
 idc(p);
 return *p;
}
int test21(int *q, int *x) {
 if (q)
  ;
 if (x)
  ;
 int *p = q;
 return *p;
}
int test22(int *q, int *x) {
  idc(q);
 if (x)
  ;
 int *p = q;
 return *p;
}
int test23(int *q, int *x) {
  idc(q);
 if (x)
  ;
 int *p = q;
  if (!p)
    ;
 return *p;
}
void use(char *p) {
  if (!p)
    return;
  p[0] = 'a';
}
void test24(char *buffer) {
  use(buffer);
  buffer[1] = 'b';
}
void idcchar(const char *s2) {
  if(s2)
    ;
}
void testConstantOffset(char *value) {
  char *cursor = value + 5;
  idcchar(cursor);
  if (*cursor) {
    cursor++;
  }
}
void idcZero(int assume) {
  if (assume)
    ;
}
int idcTriggerZeroValue(int m) {
  idcZero(m);
  return 5/m;
}
int idcTriggerZeroValueThroughCall(int i) {
  return 5/i;
}
void idcTrackZeroValueThroughCall(int x) {
  idcZero(x);
  idcTriggerZeroValueThroughCall(x);
}
int idcTriggerZeroThroughDoubleAssignemnt(int i) {
  return 5/i;
}
void idcTrackZeroThroughDoubleAssignemnt(int x) {
  idcZero(x);
  int y = x;
  int z = y;
  idcTriggerZeroValueThroughCall(z);
}
struct S {
  int f1;
  int f2;
};
void idcTrackZeroValueThroughUnaryPointerOperators(struct S *s) {
  idc(s);
  *(&(s->f1)) = 7;
}
void idcTrackZeroValueThroughUnaryPointerOperatorsWithOffset1(struct S *s) {
  idc(s);
  int *x = &(s->f2);
  *x = 7;
}
void idcTrackZeroValueThroughUnaryPointerOperatorsWithOffset2(struct S *s) {
  idc(s);
  int *x = &(s->f2) - 1;
  *x = 7;
}
void idcTrackZeroValueThroughUnaryPointerOperatorsWithAssignment(struct S *s) {
  idc(s);
  int *x = &(s->f1);
  *x = 7;
}
struct S2 {
  int a[1];
};
void idcTrackZeroValueThroughUnaryPointerOperatorsWithArrayField(struct S2 *s) {
  idc(s);
  *(&(s->a[0])) = 7;
}
