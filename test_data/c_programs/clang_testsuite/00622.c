struct edge_rec
{
  struct VERTEX *v;
  struct edge_rec *next;
  int wasseen;
  int more_data;
};
typedef struct edge_rec *QUAD_EDGE;
typedef struct {
  QUAD_EDGE left, right;
} EDGE_PAIR;
struct EDGE_STACK {
    int ptr;
    QUAD_EDGE *elts;
    int stack_size;
};
int do_merge(QUAD_EDGE ldo, QUAD_EDGE rdo) {
  int lvalid;
  QUAD_EDGE basel,rcand;
  while (1) {
    if (!lvalid) {
      return (int)basel->next;
    }
  }
}
