int a;
int a = 242;
int c __attribute__((weak))= 0;
const int d __attribute__((weak))= 0;
struct ManyFields {
  int a;
  int b;
  int c;
  char d;
  int e;
  int f;
};
struct ManyFields FewInits = {1, 2};
typedef int wchar_t;
struct K {
  wchar_t L[6];
  int M;
} l = { { L"foo" }, 1 };
char yuv_types[4][6]= {"4:0:0","4:2:0","4:2:2","4:4:4"};
int b __attribute__((section("foo")));
