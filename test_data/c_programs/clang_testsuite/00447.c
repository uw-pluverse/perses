struct list {
  int x;
  struct list *Next;
};
static struct list B;
static struct list A = { 7, &B };
static struct list B = { 8, &A };
extern struct list D;
struct list C = { 7, &D };
struct list D = { 8, &C };
