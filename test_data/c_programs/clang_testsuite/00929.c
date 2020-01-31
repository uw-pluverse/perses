static int staticVar;
static int staticFunction();
static struct { int x; } staticStruct;
inline int useStatic () {
  staticFunction();
  (void)staticStruct.x;
  return staticVar;
}
extern inline int useStaticFromExtern () {
  staticFunction();
  return staticVar;
}
static inline int useStaticFromStatic () {
  staticFunction();
  return staticVar;
}
extern inline int useStaticInlineFromExtern () {
  return useStaticFromStatic();
}
static int constFunction() __attribute__((const));
inline int useConst () {
  return constFunction();
}
inline int a;
typedef inline int b;
int d(inline int a);
inline int useStaticMainFile () {
  staticFunction();
  return staticVar;
}
#pragma clang diagnostic push
#pragma clang diagnostic warning "-Wstatic-in-inline"
inline int useStaticAgain () {
  staticFunction();
  return staticVar;
}
#pragma clang diagnostic pop
inline void defineStaticVar() {
  static const int x = 0;
  static int y = 0;
}
extern inline void defineStaticVarInExtern() {
  static const int x = 0;
  static int y = 0;
}
inline int useStaticMainFileInLineMarker() {
  staticFunction();
  return staticVar;
}
inline int useStaticMainFileAfterLineMarker() {
  staticFunction();
  return staticVar;
}
