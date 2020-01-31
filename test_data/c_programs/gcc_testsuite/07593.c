






struct t
{
  int a;
  int b;
  int c;
};

union u
{
  int n;
  float i;
};

struct multilevel
{
   int x;
   struct t t;
   union u u;
   union u v;
   char *f;
};

struct t T0 = { 1 };

struct t T1 = { .a = 1 };

union u U0 = { 1 };
union u U1 = { .i = 1 };

struct multilevel M =
{
  12,
  { .b = 3 },
  { 4 },
  { .n = 9 },

};
