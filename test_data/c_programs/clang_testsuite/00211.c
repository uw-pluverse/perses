typedef int Int;
typedef float Float;
struct S0 {
  Int field1;
  Float field2;
};
struct S0 x0;
struct S1 {
  Int field1;
  int field2;
};
struct S1 x1;
struct S2 { int i; float f; } x2;
struct S3 { int i; float f; double d; } x3;
struct S4 { int i; } x4;
struct S5 { int i : 8; unsigned j : 8; } x5;
struct S6 { int i : 8; unsigned j : 8; } x6;
struct S7 { int i : 8; unsigned j : 8; } x7;
struct S8 *x8;
struct S9 { int i; float f; } *x9;
struct S10 *x10;
struct ListNode {
  int value;
  struct ListNode *Next;
} xList;
struct DeepError {
  int value;
  struct DeeperError { int i; int f; } *Deeper;
} xDeep;
struct {
  Int i;
  float f;
} x11;
typedef struct {
  Int i;
  float f;
} S12;
S12 x12;
typedef struct {
  Float i;
  float f;
} S13;
S13 x13;
