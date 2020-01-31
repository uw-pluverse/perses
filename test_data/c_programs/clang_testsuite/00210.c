struct S0 {
  int field1;
  float field2;
};
struct S0 x0;
struct S1 {
  int field1;
  float field2;
};
struct S1 x1;
union S2 { int i; float f; } x2;
struct S3 { int i; float f; } x3;
struct S4 { int i; float f; } x4;
struct S5 { int i : 8; unsigned j : 8; } x5;
struct S6 { int i : 8; unsigned j; } x6;
struct S7 { int i : 8; unsigned j : 16; } x7;
struct S8 { int i; float f; } *x8;
struct S9 *x9;
struct S10 *x10;
struct ListNode {
  int value;
  struct ListNode *Next;
} xList;
struct DeepError {
  int value;
  struct DeeperError { int i; float f; } *Deeper;
} xDeep;
struct {
  int i;
  float f;
} x11;
typedef struct {
  int i;
  float f;
} S12;
S12 x12;
typedef struct {
  int i;
  float f;
} S13;
S13 x13;
