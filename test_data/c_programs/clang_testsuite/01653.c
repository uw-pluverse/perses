#pragma pack(push, 1)
struct s0 {
  char c;
  int x;
};
extern int a[sizeof(struct s0) == 5 ? 1 : -1];
#pragma options align=natural
struct s1 {
  char c;
  int x;
};
extern int a[sizeof(struct s1) == 8 ? 1 : -1];
#pragma options align=reset
#pragma options align=native
struct s1_1 {
  char c;
  int x;
};
extern int a[sizeof(struct s1_1) == 8 ? 1 : -1];
#pragma pack(pop)
struct s2 {
  char c;
  int x;
};
extern int a[sizeof(struct s2) == 5 ? 1 : -1];
#pragma pack(pop)
struct s3 {
  char c;
  int x;
};
extern int a[sizeof(struct s3) == 8 ? 1 : -1];
#pragma pack(push,2)
#pragma options align=power
struct s4 {
  char c;
  int x;
};
#pragma pack(pop)
#pragma options align=reset
extern int a[sizeof(struct s4) == 8 ? 1 : -1];
#pragma options align=reset
#pragma pack(pop)
