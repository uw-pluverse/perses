



typedef enum { E1, E2 } E;

typedef struct
{
  E e;
  union
  {
    int i;
    char *c;
  };
} S;

S s;

typedef int T;

struct U
{
  T t;
  union { int i; };
};
