




typedef struct
{
  int i;
} s0;

typedef union
{
  int i;
} u0;

struct s1
{
  int a;
  u0;
  struct
  {
    int b;
  };
};

union u1
{
  int b;
  s0;
  union
  {
    int c;
  };
};
