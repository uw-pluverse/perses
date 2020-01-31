void ints(int a, int b, int c, int d) {}
void floats(float a, float b, float c, float d) {}
void mixed(int a, float b, int c, float d) {}
void doubles(double d1, double d2) {}
void mixedDoubles(int a, double d1) {}
typedef struct st3_t {
  char a[3];
} st3_t;
typedef struct st4_t {
  int a;
} st4_t;
typedef struct st5_t {
  int a;
  char b;
} st5_t;
typedef struct st12_t {
  int a;
  int b;
  int c;
} st12_t;
void smallStructs(st4_t st1, st4_t st2, st4_t st3) {}
void paddedStruct(int i1, st5_t st, st4_t st4) {}
void largeStructBegin(st12_t st) {}
void largeStructMiddle(int i1, st12_t st, int i2, int i3) {}
void largeStructEnd(int i1, int i2, int i3, st12_t st) {}
st3_t retNonPow2Struct(st3_t r) { return r; }
st4_t retSmallStruct(st4_t r) { return r; }
st5_t retPaddedStruct(st5_t r) { return r; }
st12_t retLargeStruct(int i1, st12_t r) { return r; }
int varArgs(int i1, ...) { return i1; }
long double longDoubleArg(long double ld1) { return ld1; }
