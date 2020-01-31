#pragma pack(push, 1)
#pragma pack(push, 4)
#pragma pack()
#pragma pack(pop)
struct s0 {
  char f0;
  short f1;
};
int a[sizeof(struct s0) == 3 ? 1 : -1];
#pragma pack(pop)
struct s1 {
  char f0;
  short f1;
};
int b[sizeof(struct s1) == 4 ? 1 : -1];
