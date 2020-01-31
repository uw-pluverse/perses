void clang_analyzer_eval(int);
int string_literal_init() {
  char a[] = "abc";
  char b[2] = "abc";
  char c[5] = "abc";
  clang_analyzer_eval(a[1] == 'b');
  clang_analyzer_eval(b[1] == 'b');
  clang_analyzer_eval(c[1] == 'b');
  clang_analyzer_eval(a[3] == 0);
  clang_analyzer_eval(c[3] == 0);
  clang_analyzer_eval(c[4] == 0);
  return 42;
}
void nested_compound_literals(int rad) {
  int vec[6][2] = {{0.195, 0.02}, {0.383, 0.067}, {0.55, 0.169},
                   {0.831, 0.45}, {0.924, 0.617}, {0.98, 0.805}};
  int a;
  for (a = 0; a < 6; ++a) {
      vec[a][0] *= rad;
      vec[a][1] *= rad;
  }
}
void nested_compound_literals_float(float rad) {
  float vec[6][2] = {{0.195, 0.02}, {0.383, 0.067}, {0.55, 0.169},
                     {0.831, 0.45}, {0.924, 0.617}, {0.98, 0.805}};
  int a;
  for (a = 0; a < 6; ++a) {
      vec[a][0] *= rad;
      vec[a][1] *= rad;
  }
}
void struct_as_array() {
  struct simple { int x; int y; };
  struct simple a;
  struct simple *p = &a;
  p->x = 5;
  clang_analyzer_eval(a.x == 5);
  clang_analyzer_eval(p[0].x == 5);
  p[0].y = 5;
  clang_analyzer_eval(a.y == 5);
  clang_analyzer_eval(p->y == 5);
}
struct point { int x; int y; };
struct circle { struct point o; int r; };
struct circle get_circle() {
  struct circle result;
  result.r = 5;
  result.o = (struct point){0, 0};
  return result;
}
void struct_in_struct() {
  struct circle c;
  c = get_circle();
  clang_analyzer_eval(c.r == 5);
}
struct circle_f { struct point o; float r; };
struct circle_f get_circle_f() {
  struct circle_f result;
  result.r = 5.0;
  result.o = (struct point){0, 0};
  return result;
}
float struct_in_struct_f() {
  struct circle_f c;
  c = get_circle_f();
  return c.r;
}
int randomInt();
int testSymbolicInvalidation(int index) {
  int vals[10];
  vals[0] = 42;
  clang_analyzer_eval(vals[0] == 42);
  vals[index] = randomInt();
  clang_analyzer_eval(vals[0] == 42);
  return vals[index];
}
int testConcreteInvalidation(int index) {
  int vals[10];
  vals[index] = 42;
  clang_analyzer_eval(vals[index] == 42);
  vals[0] = randomInt();
  clang_analyzer_eval(vals[index] == 42);
  return vals[0];
}
typedef struct {
  int x, y, z;
} S;
S makeS();
int testSymbolicInvalidationStruct(int index) {
  S vals[10];
  vals[0].x = 42;
  clang_analyzer_eval(vals[0].x == 42);
  vals[index] = makeS();
  clang_analyzer_eval(vals[0].x == 42);
  return vals[index].x;
}
int testConcreteInvalidationStruct(int index) {
  S vals[10];
  vals[index].x = 42;
  clang_analyzer_eval(vals[index].x == 42);
  vals[0] = makeS();
  clang_analyzer_eval(vals[index].x == 42);
  return vals[0].x;
}
typedef struct {
  S a[5];
  S b[5];
} SS;
int testSymbolicInvalidationDoubleStruct(int index) {
  SS vals;
  vals.a[0].x = 42;
  vals.b[0].x = 42;
  clang_analyzer_eval(vals.a[0].x == 42);
  clang_analyzer_eval(vals.b[0].x == 42);
  vals.a[index] = makeS();
  clang_analyzer_eval(vals.a[0].x == 42);
  clang_analyzer_eval(vals.b[0].x == 42);
  return vals.b[index].x;
}
int testConcreteInvalidationDoubleStruct(int index) {
  SS vals;
  vals.a[index].x = 42;
  vals.b[index].x = 42;
  clang_analyzer_eval(vals.a[index].x == 42);
  clang_analyzer_eval(vals.b[index].x == 42);
  vals.a[0] = makeS();
  clang_analyzer_eval(vals.a[index].x == 42);
  clang_analyzer_eval(vals.b[index].x == 42);
  return vals.b[0].x;
}
int testNonOverlappingStructFieldsSimple() {
  S val;
  val.x = 1;
  val.y = 2;
  clang_analyzer_eval(val.x == 1);
  clang_analyzer_eval(val.y == 2);
  return val.z;
}
int testNonOverlappingStructFieldsSymbolicBase(int index, int anotherIndex) {
  SS vals;
  vals.a[index].x = 42;
  vals.a[index].y = 42;
  clang_analyzer_eval(vals.a[index].x == 42);
  clang_analyzer_eval(vals.a[index].y == 42);
  vals.a[anotherIndex].x = 42;
  clang_analyzer_eval(vals.a[index].x == 42);
  clang_analyzer_eval(vals.a[index].y == 42);
  return vals.a[index].z;
}
int testStructFieldChains(int index, int anotherIndex) {
  SS vals[4];
  vals[index].a[0].x = 42;
  vals[anotherIndex].a[1].y = 42;
  clang_analyzer_eval(vals[index].a[0].x == 42);
  clang_analyzer_eval(vals[anotherIndex].a[1].y == 42);
  vals[anotherIndex].b[1].x = 42;
  clang_analyzer_eval(vals[index].a[0].x == 42);
  clang_analyzer_eval(vals[anotherIndex].a[1].y == 42);
  clang_analyzer_eval(vals[anotherIndex].b[1].x == 42);
  vals[index].a[anotherIndex].x = 42;
  clang_analyzer_eval(vals[index].a[0].x == 42);
  clang_analyzer_eval(vals[anotherIndex].a[0].x == 42);
  clang_analyzer_eval(vals[anotherIndex].a[1].y == 42);
  clang_analyzer_eval(vals[anotherIndex].b[1].x == 42);
  return vals[index].a[0].z;
}
int testStructFieldChainsNested(int index, int anotherIndex) {
  SS vals[4];
  vals[index].a[0].x = 42;
  clang_analyzer_eval(vals[index].a[0].x == 42);
  vals[index].b[0] = makeS();
  clang_analyzer_eval(vals[index].a[0].x == 42);
  vals[index].a[0] = makeS();
  clang_analyzer_eval(vals[index].a[0].x == 42);
  vals[index].a[0].x = 42;
  clang_analyzer_eval(vals[index].a[0].x == 42);
  return 0;
}
typedef struct {
  int zoomLevel;
  struct point center;
} Outer;
extern int test13116945(struct point x);
static void radar13116945(struct point centerCoordinate) {
  Outer zoomRegion;
  zoomRegion.zoomLevel = 0;
  zoomRegion.center = centerCoordinate;
  Outer r = zoomRegion;
  test13116945(r.center);
}
typedef struct {
  char data[4];
} ShortString;
typedef struct {
  ShortString str;
  int length;
} ShortStringWrapper;
void testArrayStructCopy() {
  ShortString s = { "abc" };
  ShortString s2 = s;
  ShortString s3 = s2;
  clang_analyzer_eval(s3.data[0] == 'a');
  clang_analyzer_eval(s3.data[1] == 'b');
  clang_analyzer_eval(s3.data[2] == 'c');
  s3.data[0] = 'z';
  ShortString s4 = s3;
  clang_analyzer_eval(s4.data[0] == 'z');
  clang_analyzer_eval(s4.data[1] == 'b');
  clang_analyzer_eval(s4.data[2] == 'c');
}
void testArrayStructCopyNested() {
  ShortString s = { "abc" };
  ShortString s2 = s;
  ShortStringWrapper w = { s2, 0 };
  clang_analyzer_eval(w.str.data[0] == 'a');
  clang_analyzer_eval(w.str.data[1] == 'b');
  clang_analyzer_eval(w.str.data[2] == 'c');
  clang_analyzer_eval(w.length == 0);
  ShortStringWrapper w2 = w;
  clang_analyzer_eval(w2.str.data[0] == 'a');
  clang_analyzer_eval(w2.str.data[1] == 'b');
  clang_analyzer_eval(w2.str.data[2] == 'c');
  clang_analyzer_eval(w2.length == 0);
  ShortStringWrapper w3 = w2;
  clang_analyzer_eval(w3.str.data[0] == 'a');
  clang_analyzer_eval(w3.str.data[1] == 'b');
  clang_analyzer_eval(w3.str.data[2] == 'c');
  clang_analyzer_eval(w3.length == 0);
}
int testMixSymbolicAndConcrete(int index, int anotherIndex) {
  SS vals;
  vals.a[index].x = 42;
  vals.a[0].y = 42;
  clang_analyzer_eval(vals.a[index].x == 42);
  clang_analyzer_eval(vals.a[0].y == 42);
  vals.a[anotherIndex].y = 42;
  clang_analyzer_eval(vals.a[index].x == 42);
  clang_analyzer_eval(vals.a[0].y == 42);
  return vals.a[0].x;
}
void testFieldChainIsNotEnough(int index) {
  SS vals[4];
  vals[index].a[0].x = 42;
  clang_analyzer_eval(vals[index].a[0].x == 42);
  vals[index].a[1] = makeS();
  clang_analyzer_eval(vals[index].a[0].x == 42);
}
