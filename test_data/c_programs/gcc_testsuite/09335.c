

typedef struct s { const int i; } s;
union u {const int a; double b;};
struct ts { int a; s v;};
struct ta { int a; s v[2];};

void f ()
{
  s v1;
  s va[2];
  union u v2;
  struct ts v3;
  struct ta ta[2];
}
