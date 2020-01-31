int opaquePropertyCheck(void *object);
int coin();
int *getNull() {
  return 0;
}
int* getPtr();
int *dynCastToInt(void *ptr) {
  if (opaquePropertyCheck(ptr))
    return (int *)ptr;
  return 0;
}
int *dynCastOrNull(void *ptr) {
  if (!ptr)
    return 0;
  if (opaquePropertyCheck(ptr))
    return (int *)ptr;
  return 0;
}
void testDynCast(void *p) {
  int *casted = dynCastToInt(p);
  *casted = 1;
}
void testDynCastOrNull(void *p) {
  int *casted = dynCastOrNull(p);
  *casted = 1;
}
void testBranch(void *p) {
  int *casted;
  if (coin()) {
    casted = dynCastToInt(p);
  } else {
    if (p)
      return;
    casted = (int *)p;
  }
  *casted = 1;
}
void testBranchReversed(void *p) {
  int *casted;
  if (coin()) {
    if (p)
      return;
    casted = (int *)p;
  } else {
    casted = dynCastToInt(p);
  }
  *casted = 1;
}
void testMultipleStore(void *p) {
  int *casted = 0;
  casted = dynCastToInt(p);
  *casted = 1;
}
int retZero() {
  return 0;
}
int triggerDivZero () {
  int y = retZero();
  return 5/y;
}
void testInlineCheckInMacro(int *p) {
  int i = ( ((p) != 0) ? *p : 17);
  (void)i;
  *p = 1;
}
void testInlineCheckInNestedMacro(int *p) {
  int i = ( { int j = ( ((p) != 0) ? *p : 17); j; } );
  (void)i;
  *p = 1;
}
void testNonFunctionMacro(int *p) {
  int i = ( ((p) != 0) ? *p : 17) ;
  (void)i;
  *p = 1;
}
void testErrorInMacro(int *p) {
  int i = ( ((p) != 0) ? 0 : *p);
  (void)i;
}
void testMacroUsedAsGuard(int *p) {
  if ((!(p)))
    *p = 1;
}
int isNull(int *p);
int isEqual(int *p, int *q);
void testNestedDisjunctiveMacro(int *p, int *q) {
  if ((!((int *)(p) == (int *)(q) || (((p) == 0 || isNull(p)) && ((q) == 0 || isNull(q))) || isEqual(p,q)))) {
    *p = 1;
    *q = 1;
  }
  *p = 1;
  *q = 1;
}
void testNestedDisjunctiveMacro2(int *p, int *q) {
  if (((int *)(p) == (int *)(q) || (((p) == 0 || isNull(p)) && ((q) == 0 || isNull(q))) || isEqual(p,q))) {
    return;
  }
  *p = 1;
  *q = 1;
}
void testErrorInArgument(int *p) {
  int i = ((p ? 0 : *p));
  (void)i;
}
void testDynCastOrNullOfNull() {
  int *casted = dynCastOrNull(0);
  *casted = 1;
}
void testDynCastOfNull() {
  int *casted = dynCastToInt(0);
  *casted = 1;
}
int *lookUpInt(int unused) {
  if (coin())
    return 0;
  static int x;
  return &x;
}
void testZeroIsNotNull() {
  int *casted = lookUpInt(0);
  *casted = 1;
}
void testTrackNull() {
  int *casted = dynCastOrNull(getNull());
  *casted = 1;
}
void testTrackNullVariable() {
  int *ptr;
  ptr = getNull();
  int *casted = dynCastOrNull(ptr);
  *casted = 1;
}
void inlinedIsDifferent(int inlined) {
  int i;
  int *p = inlined ? &i : getNull();
  if (!inlined)
    inlinedIsDifferent(1);
  *p = 1;
}
void testInlinedIsDifferent() {
  inlinedIsDifferent(0);
}
void testNoArguments() {
  int *casted = getNull();
  *casted = 1;
}
int *getNullIfNonNull(void *input) {
  if (input)
    return 0;
  static int x;
  return &x;
}
void testKnownPath(void *input) {
  if (!input)
    return;
  int *casted = getNullIfNonNull(input);
  *casted = 1;
}
int *alwaysReturnNull(void *input) {
  if (opaquePropertyCheck(input))
    return 0;
  return 0;
}
void testAlwaysReturnNull(void *input) {
  int *casted = alwaysReturnNull(input);
  *casted = 1;
}
int derefArg(int *p) {
 return *p;
}
void ternaryArg(char cond) {
 static int x;
 derefArg(cond ? &x : getNull());
}
int derefArgCast(char *p) {
 return *p;
}
void ternaryArgCast(char cond) {
 static int x;
 derefArgCast((char*)((unsigned)cond ? &x : getNull()));
}
int derefAssignment(int *p) {
 return *p;
}
void ternaryAssignment(char cond) {
  static int x;
  int *p = cond ? getNull() : getPtr();
  derefAssignment(p);
}
int *retNull(char cond) {
  static int x;
  return cond ? &x : getNull();
}
int ternaryRetNull(char cond) {
  int *p = retNull(cond);
  return *p;
}
int testConditionalOperatorSuppress(int x) {
  return *(x ? getNull() : getPtr());
}
int testNestedConditionalOperatorSuppress(int x) {
  return *(x ? (x ? getNull() : getPtr()) : getPtr());
}
int testConditionalOperator(int x) {
  return *(x ? 0 : getPtr());
}
int testNestedConditionalOperator(int x) {
  return *(x ? (x ? 0 : getPtr()) : getPtr());
}
int testConditionalOperatorSuppressFloatCond(float x) {
  return *(x ? getNull() : getPtr());
}
