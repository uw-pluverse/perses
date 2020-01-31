






struct {
  struct {
    int x;
    int y;
  } p;
} v;

int *z = &((&(v.p))->y);
